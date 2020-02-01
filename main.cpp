#include <fstream>

const std::string header =
"#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)\n"
"#include <cxxabi.h>\n"
"#include <memory>\n"
"static std::string demangle(const char* name) {\n"
"    auto demangledName = abi::__cxa_demangle(name, 0, 0, nullptr);\n"
"    auto result = std::string(demangledName);\n"
"    free(demangledName);\n"
"    return result;\n"
"}\n"
"#define DEMANGLE(CLASS) demangle(CLASS)\n"
"#elif defined(_MSC_VER)\n"
"#define DEMANGLE(CLASS) CLASS\n"
"#endif\n"
"\n"
"#include <unistd.h>\n"
"#include <sys/times.h>\n"
"\n"
"using ClockType = decltype(times(nullptr));\n"
"\n"
"struct tms start, end;\n"
"ClockType clock_start, clock_end;\n"
"\n"
"#define START_TIME() \\\n"
"clock_start = times(&start);\n"
"\n"
"#define END_TIME() \\\n"
"clock_end = times(&end);\n"
"\n"
"#define DELTA_TIME() \\\n"
"(double(end.tms_utime - start.tms_utime) / sysconf(_SC_CLK_TCK))\n"
;

const std::string main_header =
"#include <fstream>\n"
"int main() {\n"
;

std::string main_init_out(size_t count) {
    return
        "auto sfout = std::ofstream(std::string(\"switch\") + \".txt\");\n"
        "auto iefout = std::ofstream(std::string(\"ifelse\") + \".txt\");\n";
}

const std::string switch_out_stream = "sfout";
const std::string ifelse_out_stream = "iefout";

const std::string main_footer =
"   return 0;\n"
"}\n"
;


enum class JMP {
    IF_ELSE,
    SWITCH,
};

template<JMP jmp_type = JMP::IF_ELSE>
void create_test(std::ofstream& ofstream, size_t count_jmps) {
    ofstream
        << "auto test_if_else" << count_jmps
        << "() -> decltype(DELTA_TIME()) {\n"
        << "volatile auto variable = random() % " << count_jmps << ";\n"
        << "START_TIME();\n"
        ;
    for (size_t i = 0; i < count_jmps; ++i) {        
        ofstream
            << (!i ? "if " : "else if ")
            << "(variable == "
            << i
            << ") { volatile auto temp = variable + " << random() % 199 << "; }\n"
            ;
    }
    ofstream
        << "END_TIME();\n"
        << "return DELTA_TIME();\n"
        << "}\n";
}

template<>
void create_test<JMP::SWITCH>(std::ofstream& ofstream, size_t count_jmps) {
    ofstream
        << "auto test_switch" << count_jmps
        << "() -> decltype(DELTA_TIME()) {\n"
        << "volatile auto variable = random() % " << count_jmps << ";\n"
        << "START_TIME();\n"
        ;
    ofstream
        << "switch (variable) {\n"; 
    for (size_t i = 0; i < count_jmps; ++i) {        
        ofstream
            << "case (" << i << "):"
            << "{ volatile auto temp = variable + " << random() % 199 << "; } break;\n"
            ;
    }
    ofstream
        << "};\n";
    ofstream
        << "END_TIME();\n"
        << "return DELTA_TIME();\n"
        << "}\n";
}

template<JMP jmp_type = JMP::IF_ELSE>
void enable_test(std::ofstream& ofstream, size_t count_jmps) {
    ofstream
        << ifelse_out_stream
        << " << " << count_jmps << " << \" \""
        << " << test_if_else" << count_jmps << "() << std::endl;\n";
}

template<>
void enable_test<JMP::SWITCH>(std::ofstream& ofstream, size_t count_jmps) {
    ofstream
        << switch_out_stream
        << " << " << count_jmps << " << \" \""
        << " << test_switch" << count_jmps << "() << std::endl;\n";
}

int main() {
    const auto start_count = 10;
    const auto end_count = 500;
    const auto step = 10;
    auto fout = std::ofstream(std::string("test_") + std::to_string(start_count) + "_" + std::to_string(end_count) + ".cpp");
    fout << header;
    for (size_t i = start_count; i < end_count; i += step) {
        create_test<JMP::IF_ELSE>(fout, i);
        create_test<JMP::SWITCH>(fout, i);
    }
    fout << main_header;
    fout << main_init_out(end_count);
    for (size_t i = start_count; i < end_count; i += step) {
        enable_test<JMP::IF_ELSE>(fout, i);        
    }
    for (size_t i = start_count; i < end_count; i += step) {
        enable_test<JMP::SWITCH>(fout, i);        
    }
    fout << main_footer;
    return 0;
}