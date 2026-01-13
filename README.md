# LeetCode Projesi

C++ ile LeetCode problem çözümleri. Çözümler direkt LeetCode'a kopyalanabilir.

## Derleme

```bash
cd LeetCode_Projects
```

```bash
mkdir build && cd build
cmake ..
make
```

## Çalıştırma

```bash
./LeetCode_Projects list      # Problemleri listele
./LeetCode_Projects 1         # Two Sum çalıştır
./LeetCode_Projects all       # Hepsini çalıştır
```

## Yeni Problem Ekleme

### 1. Dosya Oluştur

`src/solutions/kategori/XXX_problem_adi.cpp` dosyası oluştur.

Kategoriler: `array`, `string`, `math`, `two_pointers`, `matrix`, `graph`

### 2. Şablonu Kullan

```cpp
/*
 * LeetCode #XXX - Problem Adı
 * https://leetcode.com/problems/problem-adi/
 * Difficulty: Easy/Medium/Hard
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int solve(vector<int>& nums) {
        // Çözümünü buraya yaz
        return 0;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace pXXX {
void test() {
    Solution sol;
    
    vector<int> nums1 = {1, 2, 3};
    cout << "Test 1: " << sol.solve(nums1) << " (expected: X)" << endl;
}
REGISTER_PROBLEM(XXX, "Problem Adı")
}
```

### 3. Derle ve Çalıştır

```bash
cd build
make
./LeetCode_Projects XXX
```

## LeetCode'a Kopyalama

`// ==================== LEETCODE SOLUTION START ====================`

`// ==================== LEETCODE SOLUTION END ====================` 

arasındaki `class Solution` kısmını direkt LeetCode'a kopyala.

## Proje Yapısı

```
LeetCode_Projects/
├── CMakeLists.txt
├── README.md
├── include/
│   └── registry.hpp        # Test runner (sadece lokal)
└── src/
    ├── main.cpp
    └── solutions/
        ├── array/
        ├── string/
        ├── math/
        ├── two_pointers/
        ├── matrix/
        └── graph/
```

## Notlar

- `class Solution` LeetCode formatında - direkt kopyalanabilir
- `using namespace std;` kullanılıyor - LeetCode ile uyumlu
- `registry.hpp` sadece lokal test için, LeetCode'a kopyalanmaz
