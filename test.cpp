#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
#include <cxxabi.h>
#include <memory>
static std::string demangle(const char* name) {
    auto demangledName = abi::__cxa_demangle(name, 0, 0, nullptr);
    auto result = std::string(demangledName);
    free(demangledName);
    return result;
}
#define DEMANGLE(CLASS) demangle(CLASS)
#elif defined(_MSC_VER)
#define DEMANGLE(CLASS) CLASS
#endif
///
#include <unistd.h>
#include <sys/times.h>

using ClockType = decltype(times(nullptr));

struct tms start, end;
ClockType clock_start, clock_end;

#define START_TIME() \
clock_start = times(&start);

#define END_TIME() \
clock_end = times(&end);

#define DELTA_TIME() \
(double(end.tms_utime - start.tms_utime) / sysconf(_SC_CLK_TCK)) 
//

//
#include <sys/mman.h>

template<typename T>
T min(const T& v1, const T& v2) {
    return v1 > v2 ? v2 : v1;
}

#include <vector>
auto test_switch(size_t size, size_t count) -> decltype(DELTA_TIME()) {
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        arr.emplace_back(random() % min(count, size_t(30)));
    }

    volatile auto variable = 24;
    START_TIME();
    for (auto i = 0; i < size; ++i) {
        switch (arr[i]) {
        case 0: {
            variable = 0;
        } break;
        case 1: {
            variable = 1;
        } break;
        case 2: {
            variable = 2;
        } break;
        case 3: {
            variable = 3;
        } break;
        case 4: {
            variable = 4;
        } break;
        case 5: {
            variable = 5;
        } break;
        case 6: {
            variable = 6;
        } break;
        case 7: {
            variable = 7;
        } break;
        case 8: {
            variable = 8;
        } break;
        case 9: {
            variable = 9;
        } break;
        case 10: {
            variable = 10;
        } break;
        case 11: {
            variable = 11;
        } break;
        case 12: {
            variable = 12;
        } break;
        case 13: {
            variable = 13;
        } break;
        case 14: {
            variable = 14;
        } break;
        case 15: {
            variable = 15;
        } break;
        case 16: {
            variable = 16;
        } break;
        case 17: {
            variable = 17;
        } break;
        case 18: {
            variable = 18;
        } break;
        case 19: {
            variable = 19;
        } break;
        case 20: {
            variable = 20;
        } break;
        case 21: {
            variable = 21;
        } break;
        case 22: {
            variable = 22;
        } break;
        case 23: {
            variable = 23;
        } break;
        case 24: {
            variable = 24;
        } break;
        case 25: {
            variable = 25;
        } break;
        case 26: {
            variable = 26;
        } break;
        case 27: {
            variable = 27;
        } break;
        case 28: {
            variable = 28;
        } break;
        case 29: {
            variable = 29;
        } break;
        case 30: {
            variable = 30;
        } break;
        case 31: {
            variable = 31;
        } break;
        case 32: {
            variable = 32;
        } break;
        case 33: {
            variable = 33;
        } break;
        case 34: {
            variable = 34;
        } break;
        case 35: {
            variable = 35;
        } break;
        case 36: {
            variable = 36;
        } break;
        case 37: {
            variable = 37;
        } break;
        case 38: {
            variable = 38;
        } break;
        case 39: {
            variable = 39;
        } break;
        default: break;
        }        
    }
    END_TIME();

    return DELTA_TIME();
}

auto test_if_else(size_t size, size_t count) -> decltype(DELTA_TIME()) {
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        arr.emplace_back(random() % min(count, size_t(30)));
    }

    volatile auto variable = 1399;
    START_TIME();
    for (auto i = 0; i < size; ++i) {
        if (arr[i] == 0) { variable = 0; }
        else if (arr[i] == 1) { variable = 1; }
        else if (arr[i] == 2) { variable = 2; }
        else if (arr[i] == 3) { variable = 3; }
        else if (arr[i] == 4) { variable = 4; }
        else if (arr[i] == 5) { variable = 5; }
        else if (arr[i] == 6) { variable = 6; }
        else if (arr[i] == 7) { variable = 7; }
        else if (arr[i] == 8) { variable = 8; }
        else if (arr[i] == 9) { variable = 9; }
        else if (arr[i] == 10) { variable = 10; }
        else if (arr[i] == 11) { variable = 11; }
        else if (arr[i] == 12) { variable = 12; }
        else if (arr[i] == 13) { variable = 13; }
        else if (arr[i] == 14) { variable = 14; }
        else if (arr[i] == 15) { variable = 15; }
        else if (arr[i] == 16) { variable = 16; }
        else if (arr[i] == 17) { variable = 17; }
        else if (arr[i] == 18) { variable = 18; }
        else if (arr[i] == 19) { variable = 19; }
        else if (arr[i] == 20) { variable = 20; }
        else if (arr[i] == 21) { variable = 21; }
        else if (arr[i] == 22) { variable = 22; }
        else if (arr[i] == 23) { variable = 23; }
        else if (arr[i] == 24) { variable = 24; }
        else if (arr[i] == 25) { variable = 25; }
        else if (arr[i] == 26) { variable = 26; }
        else if (arr[i] == 27) { variable = 27; }
        else if (arr[i] == 28) { variable = 28; }
        else if (arr[i] == 29) { variable = 29; }
        else if (arr[i] == 30) { variable = 30; }
        else if (arr[i] == 31) { variable = 31; }
        else if (arr[i] == 32) { variable = 32; }
        else if (arr[i] == 33) { variable = 33; }
        else if (arr[i] == 34) { variable = 34; }
        else if (arr[i] == 35) { variable = 35; }
        else if (arr[i] == 36) { variable = 36; }
        else if (arr[i] == 37) { variable = 37; }
        else if (arr[i] == 38) { variable = 38; }
        else if (arr[i] == 39) { variable = 39; }
    }
    END_TIME();
    return DELTA_TIME();
}

typedef void (*func_type)(volatile int&);

void func0(volatile int& variable) {
    volatile auto temp = 0;
    variable = temp;
}
void func1(volatile int& variable) {
    volatile auto temp = 1;
    variable = temp;
}
void func2(volatile int& variable) {
    volatile auto temp = 2;
    variable = temp;
}
void func3(volatile int& variable) {
    volatile auto temp = 3;
    variable = temp;
}
void func4(volatile int& variable) {
    volatile auto temp = 4;
    variable = temp;
}
void func5(volatile int& variable) {
    volatile auto temp = 5;
    variable = temp;
}
void func6(volatile int& variable) {
    volatile auto temp = 6;
    variable = temp;
}
void func7(volatile int& variable) {
    volatile auto temp = 7;
    variable = temp;
}
void func8(volatile int& variable) {
    volatile auto temp = 8;
    variable = temp;
}
void func9(volatile int& variable) {
    volatile auto temp = 9;
    variable = temp;
}
void func10(volatile int& variable) {
    volatile auto temp = 10;
    variable = temp;
}
void func11(volatile int& variable) {
    volatile auto temp = 11;
    variable = temp;
}
void func12(volatile int& variable) {
    volatile auto temp = 12;
    variable = temp;
}
void func13(volatile int& variable) {
    volatile auto temp = 13;
    variable = temp;
}
void func14(volatile int& variable) {
    volatile auto temp = 14;
    variable = temp;
}
void func15(volatile int& variable) {
    volatile auto temp = 15;
    variable = temp;
}
void func16(volatile int& variable) {
    volatile auto temp = 16;
    variable = temp;
}
void func17(volatile int& variable) {
    volatile auto temp = 17;
    variable = temp;
}
void func18(volatile int& variable) {
    volatile auto temp = 18;
    variable = temp;
}
void func19(volatile int& variable) {
    volatile auto temp = 19;
    variable = temp;
}
void func20(volatile int& variable) {
    volatile auto temp = 20;
    variable = temp;
}
void func21(volatile int& variable) {
    volatile auto temp = 21;
    variable = temp;
}
void func22(volatile int& variable) {
    volatile auto temp = 22;
    variable = temp;
}
void func23(volatile int& variable) {
    volatile auto temp = 23;
    variable = temp;
}
void func24(volatile int& variable) {
    volatile auto temp = 24;
    variable = temp;
}
void func25(volatile int& variable) {
    volatile auto temp = 25;
    variable = temp;
}
void func26(volatile int& variable) {
    volatile auto temp = 26;
    variable = temp;
}
void func27(volatile int& variable) {
    volatile auto temp = 27;
    variable = temp;
}
void func28(volatile int& variable) {
    volatile auto temp = 28;
    variable = temp;
}
void func29(volatile int& variable) {
    volatile auto temp = 29;
    variable = temp;
}
void func30(volatile int& variable) {
    volatile auto temp = 30;
    variable = temp;
}
void func31(volatile int& variable) {
    volatile auto temp = 31;
    variable = temp;
}
void func32(volatile int& variable) {
    volatile auto temp = 32;
    variable = temp;
}
void func33(volatile int& variable) {
    volatile auto temp = 33;
    variable = temp;
}
void func34(volatile int& variable) {
    volatile auto temp = 34;
    variable = temp;
}
void func35(volatile int& variable) {
    volatile auto temp = 35;
    variable = temp;
}
void func36(volatile int& variable) {
    volatile auto temp = 36;
    variable = temp;
}
void func37(volatile int& variable) {
    volatile auto temp = 37;
    variable = temp;
}
void func38(volatile int& variable) {
    volatile auto temp = 38;
    variable = temp;
}
void func39(volatile int& variable) {
    volatile auto temp = 39;
    variable = temp;
}

auto test_func(size_t size, size_t count) -> decltype(DELTA_TIME()) {
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        arr.emplace_back(random() % min(count, size_t(30)));
    }

    std::array<func_type, 40> functions;

    volatile auto variable = 4123;
    functions[0] = &func0;
    functions[1] = &func1;
    functions[2] = &func2;
    functions[3] = &func3;
    functions[4] = &func4;
    functions[5] = &func5;
    functions[6] = &func6;
    functions[7] = &func7;
    functions[8] = &func8;
    functions[9] = &func9;
    functions[10] = &func10;
    functions[11] = &func11;
    functions[12] = &func12;
    functions[13] = &func13;
    functions[14] = &func14;
    functions[15] = &func15;
    functions[16] = &func16;
    functions[17] = &func17;
    functions[18] = &func18;
    functions[19] = &func19;
    functions[20] = &func20;
    functions[21] = &func21;
    functions[22] = &func22;
    functions[23] = &func23;
    functions[24] = &func24;
    functions[25] = &func25;
    functions[26] = &func26;
    functions[27] = &func27;
    functions[28] = &func28;
    functions[29] = &func29;
    functions[30] = &func30;
    functions[31] = &func31;
    functions[32] = &func32;
    functions[33] = &func33;
    functions[34] = &func34;
    functions[35] = &func35;
    functions[36] = &func36;
    functions[37] = &func37;
    functions[38] = &func38;
    functions[39] = &func39;

    START_TIME();
    for (auto i = 0; i < size; ++i) {
        functions[arr[i]](variable);
    }
    END_TIME();
    return DELTA_TIME();
}

extern "C" size_t self_modify(size_t);

#include <iostream>
auto test_self_modify(size_t size, size_t count) -> decltype(DELTA_TIME()) {
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        arr.emplace_back(random() % min(count, size_t(40)));
    }

    START_TIME();
    for (size_t i = 0; i < size; ++i) {
        self_modify(arr[i]);
    }
    END_TIME();
    return DELTA_TIME();
}

constexpr auto count = 40;

int change_page_permissions_of_address(size_t addr) {
    // Move the pointer to the page boundary
    int page_size = getpagesize();
    addr -= (size_t)addr % page_size;

    if(mprotect((void*)addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
        return -1;
    }

    return 0;
}

#include <fstream>
int main() {
    if (change_page_permissions_of_address((size_t)self_modify) == -1) {
        std::cout << "BAD" << std::endl;
    }

    std::ofstream fout("test.txt");
    for (size_t i = 2; i < count; ++i) {
        fout << "0 " << i << " " << test_if_else(10000000, i) << std::endl;
        fout << "1 " << i << " " << test_switch(10000000, i) << std::endl;
        fout << "2 " << i << " " << test_func(10000000, i) << std::endl;
        fout << "3 " << i << " " << test_self_modify(10000000, i) << std::endl;
    }
    // test_self_modify(3, 2);
    return 0;
}