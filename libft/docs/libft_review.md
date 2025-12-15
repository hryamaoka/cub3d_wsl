# libft テストコード集

## ft_isalpha

### 機能
文字がアルファベット（a-z, A-Z）かどうかを判定する

### テストケース
- 小文字のアルファベット
- 大文字のアルファベット
- 数字
- 記号

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char tests[] = {'a', 'Z', '5', '@', ' '};
    int i = 0;
    
    printf("=== ft_isalpha テスト ===\n");
    while (i < 5)
    {
        printf("'%c': ft=%d, std=%d -> %s\n", 
            tests[i],
            ft_isalpha(tests[i]) != 0,
            isalpha(tests[i]) != 0,
            (ft_isalpha(tests[i]) != 0) == (isalpha(tests[i]) != 0) ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_isdigit

### 機能
文字が数字（0-9）かどうかを判定する

### テストケース
- 数字
- アルファベット
- 記号

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char tests[] = {'0', '9', 'a', '@', ' '};
    int i = 0;
    
    printf("=== ft_isdigit テスト ===\n");
    while (i < 5)
    {
        printf("'%c': ft=%d, std=%d -> %s\n", 
            tests[i],
            ft_isdigit(tests[i]) != 0,
            isdigit(tests[i]) != 0,
            (ft_isdigit(tests[i]) != 0) == (isdigit(tests[i]) != 0) ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_isalnum

### 機能
文字がアルファベットまたは数字かどうかを判定する

### テストケース
- アルファベット
- 数字
- 記号
- 空白

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char tests[] = {'a', '5', '@', ' ', 'Z'};
    int i = 0;
    
    printf("=== ft_isalnum テスト ===\n");
    while (i < 5)
    {
        printf("'%c': ft=%d, std=%d -> %s\n", 
            tests[i],
            ft_isalnum(tests[i]) != 0,
            isalnum(tests[i]) != 0,
            (ft_isalnum(tests[i]) != 0) == (isalnum(tests[i]) != 0) ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_isascii

### 機能
文字がASCII文字（0-127）かどうかを判定する

### テストケース
- ASCII範囲内の文字
- ASCII範囲外の文字
- 境界値（0, 127, 128）

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int tests[] = {0, 65, 127, 128, -1};
    int i = 0;
    
    printf("=== ft_isascii テスト ===\n");
    while (i < 5)
    {
        printf("%d: ft=%d, std=%d -> %s\n", 
            tests[i],
            ft_isascii(tests[i]) != 0,
            isascii(tests[i]) != 0,
            (ft_isascii(tests[i]) != 0) == (isascii(tests[i]) != 0) ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_isprint

### 機能
文字が印字可能文字（32-126）かどうかを判定する

### テストケース
- 印字可能文字
- 制御文字
- 境界値（31, 32, 126, 127）

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int tests[] = {31, 32, 65, 126, 127};
    int i = 0;
    
    printf("=== ft_isprint テスト ===\n");
    while (i < 5)
    {
        printf("%d: ft=%d, std=%d -> %s\n", 
            tests[i],
            ft_isprint(tests[i]) != 0,
            isprint(tests[i]) != 0,
            (ft_isprint(tests[i]) != 0) == (isprint(tests[i]) != 0) ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_strlen

### 機能
文字列の長さを返す

### テストケース
- 通常の文字列
- 空文字列
- 長い文字列

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *tests[] = {"Hello", "", "42 Tokyo", "a"};
    int i = 0;
    
    printf("=== ft_strlen テスト ===\n");
    while (i < 4)
    {
        printf("\"%s\": ft=%zu, std=%zu -> %s\n", 
            tests[i],
            ft_strlen(tests[i]),
            strlen(tests[i]),
            ft_strlen(tests[i]) == strlen(tests[i]) ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_toupper

### 機能
小文字を大文字に変換する

### テストケース
- 小文字
- 大文字
- 数字
- 記号

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char tests[] = {'a', 'Z', '5', '@'};
    int i = 0;
    
    printf("=== ft_toupper テスト ===\n");
    while (i < 4)
    {
        printf("'%c': ft='%c', std='%c' -> %s\n", 
            tests[i],
            ft_toupper(tests[i]),
            toupper(tests[i]),
            ft_toupper(tests[i]) == toupper(tests[i]) ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_tolower

### 機能
大文字を小文字に変換する

### テストケース
- 大文字
- 小文字
- 数字
- 記号

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char tests[] = {'A', 'z', '5', '@'};
    int i = 0;
    
    printf("=== ft_tolower テスト ===\n");
    while (i < 4)
    {
        printf("'%c': ft='%c', std='%c' -> %s\n", 
            tests[i],
            ft_tolower(tests[i]),
            tolower(tests[i]),
            ft_tolower(tests[i]) == tolower(tests[i]) ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_strchr

### 機能
文字列中で指定した文字が最初に現れる位置を返す

### テストケース
- 文字が存在する場合
- 文字が存在しない場合
- ヌル文字を探す場合

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str = "Hello World";
    char tests[] = {'H', 'o', 'x', '\0'};
    int i = 0;
    
    printf("=== ft_strchr テスト ===\n");
    while (i < 4)
    {
        char *ft_res = ft_strchr(str, tests[i]);
        char *std_res = strchr(str, tests[i]);
        printf("'%c': ft=%p, std=%p -> %s\n", 
            tests[i],
            (void *)ft_res,
            (void *)std_res,
            ft_res == std_res ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_strrchr

### 機能
文字列中で指定した文字が最後に現れる位置を返す

### テストケース
- 文字が複数存在する場合
- 文字が1つだけ存在する場合
- 文字が存在しない場合

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str = "Hello World";
    char tests[] = {'o', 'H', 'x', '\0'};
    int i = 0;
    
    printf("=== ft_strrchr テスト ===\n");
    while (i < 4)
    {
        char *ft_res = ft_strrchr(str, tests[i]);
        char *std_res = strrchr(str, tests[i]);
        printf("'%c': ft=%p, std=%p -> %s\n", 
            tests[i],
            (void *)ft_res,
            (void *)std_res,
            ft_res == std_res ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_strncmp

### 機能
2つの文字列をn文字まで比較する

### テストケース
- 同じ文字列
- 異なる文字列
- 部分的に同じ文字列

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s1[] = {"Hello", "Hello", "Hello", "abc"};
    char *s2[] = {"Hello", "World", "Hell", "xyz"};
    size_t n[] = {5, 5, 4, 3};
    int i = 0;
    
    printf("=== ft_strncmp テスト ===\n");
    while (i < 4)
    {
        int ft_res = ft_strncmp(s1[i], s2[i], n[i]);
        int std_res = strncmp(s1[i], s2[i], n[i]);
        printf("\"%s\" vs \"%s\" (n=%zu): ft=%d, std=%d -> %s\n", 
            s1[i], s2[i], n[i],
            ft_res, std_res,
            (ft_res == std_res || (ft_res > 0 && std_res > 0) || (ft_res < 0 && std_res < 0)) ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_strnstr

### 機能
文字列中で部分文字列を探す（最大n文字まで）

### テストケース
- 部分文字列が存在する場合（期待値：該当位置のポインタ）
- 部分文字列が存在しない場合（期待値：NULL）
- 空文字列を探す場合（期待値：haystack）
- 範囲外の場合（期待値：NULL）

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *haystack = "Hello World";
    
    printf("=== ft_strnstr テスト ===\n");
    
    // テスト1: 存在する（範囲内）
    char *result1 = ft_strnstr(haystack, "World", 11);
    printf("Test 1: \"World\" in \"Hello World\" (n=11): %s -> %s\n",
        result1 ? result1 : "NULL",
        (result1 == haystack + 6) ? "OK" : "NG");
    
    // テスト2: 存在しない
    char *result2 = ft_strnstr(haystack, "xyz", 11);
    printf("Test 2: \"xyz\" in \"Hello World\" (n=11): %s -> %s\n",
        result2 ? "Found" : "NULL",
        result2 == NULL ? "OK" : "NG");
    
    // テスト3: 空文字列
    char *result3 = ft_strnstr(haystack, "", 11);
    printf("Test 3: \"\" in \"Hello World\" (n=11): %s -> %s\n",
        result3 ? "Found" : "NULL",
        result3 == haystack ? "OK" : "NG");
    
    // テスト4: 範囲外
    char *result4 = ft_strnstr(haystack, "World", 5);
    printf("Test 4: \"World\" in \"Hello World\" (n=5): %s -> %s\n",
        result4 ? "Found" : "NULL",
        result4 == NULL ? "OK" : "NG");
    
    return (0);
}
```

---

## ft_atoi

### 機能
文字列を整数に変換する

### テストケース
- 正の数
- 負の数
- 先頭に空白がある場合
- オーバーフロー

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *tests[] = {"42", "-42", "  123", "0", "2147483647"};
    int i = 0;
    
    printf("=== ft_atoi テスト ===\n");
    while (i < 5)
    {
        int ft_res = ft_atoi(tests[i]);
        int std_res = atoi(tests[i]);
        printf("\"%s\": ft=%d, std=%d -> %s\n", 
            tests[i], ft_res, std_res,
            ft_res == std_res ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_memset

### 機能
メモリ領域を指定した値で埋める

### テストケース
- 通常のメモリ領域
- 異なるサイズ
- 異なる値

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char ft_buf[10];
    char std_buf[10];
    int vals[] = {'A', 0, 42};
    size_t lens[] = {10, 5, 10};
    int i = 0;
    
    printf("=== ft_memset テスト ===\n");
    while (i < 3)
    {
        memset(ft_buf, 0, 10);
        memset(std_buf, 0, 10);
        ft_memset(ft_buf, vals[i], lens[i]);
        memset(std_buf, vals[i], lens[i]);
        printf("val=%d, len=%zu: %s\n", 
            vals[i], lens[i],
            memcmp(ft_buf, std_buf, 10) == 0 ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_bzero

### 機能
メモリ領域をゼロで埋める

### テストケース
- 通常のメモリ領域
- 異なるサイズ

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <strings.h>
#include <string.h>

int main(void)
{
    char ft_buf[10] = "123456789";
    char std_buf[10] = "123456789";
    size_t lens[] = {10, 5, 0};
    int i = 0;
    
    printf("=== ft_bzero テスト ===\n");
    while (i < 3)
    {
        memcpy(ft_buf, "123456789", 10);
        memcpy(std_buf, "123456789", 10);
        ft_bzero(ft_buf, lens[i]);
        bzero(std_buf, lens[i]);
        printf("len=%zu: %s\n", 
            lens[i],
            memcmp(ft_buf, std_buf, 10) == 0 ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_memcpy

### 機能
メモリ領域をコピーする

### テストケース
- 通常のコピー
- 異なるサイズ
- 空のコピー

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "Hello World";
    char ft_dst[20];
    char std_dst[20];
    size_t lens[] = {11, 5, 0};
    int i = 0;
    
    printf("=== ft_memcpy テスト ===\n");
    while (i < 3)
    {
        memset(ft_dst, 0, 20);
        memset(std_dst, 0, 20);
        ft_memcpy(ft_dst, src, lens[i]);
        memcpy(std_dst, src, lens[i]);
        printf("len=%zu: %s\n", 
            lens[i],
            memcmp(ft_dst, std_dst, 20) == 0 ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_memmove

### 機能
メモリ領域をコピーする（重なりに対応）

### テストケース
- 通常のコピー
- 重なりがある場合（前方）
- 重なりがある場合（後方）

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char ft_buf1[20] = "Hello World";
    char std_buf1[20] = "Hello World";
    char ft_buf2[20] = "Hello World";
    char std_buf2[20] = "Hello World";
    
    printf("=== ft_memmove テスト ===\n");
    
    // 通常のコピー
    ft_memmove(ft_buf1, "Test", 4);
    memmove(std_buf1, "Test", 4);
    printf("通常: %s\n", memcmp(ft_buf1, std_buf1, 20) == 0 ? "OK" : "NG");
    
    // 重なり（前方）
    ft_memmove(ft_buf2 + 2, ft_buf2, 5);
    memmove(std_buf2 + 2, std_buf2, 5);
    printf("重なり(前): %s\n", memcmp(ft_buf2, std_buf2, 20) == 0 ? "OK" : "NG");
    
    // 重なり（後方）
    ft_memmove(ft_buf2, ft_buf2 + 2, 5);
    memmove(std_buf2, std_buf2 + 2, 5);
    printf("重なり(後): %s\n", memcmp(ft_buf2, std_buf2, 20) == 0 ? "OK" : "NG");
    
    return (0);
}
```

---

## ft_memchr

### 機能
メモリ領域内で指定したバイトを探す

### テストケース
- バイトが存在する場合
- バイトが存在しない場合
- ゼロバイトを探す場合

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[] = "Hello\0World";
    int vals[] = {'H', 'x', '\0'};
    size_t lens[] = {11, 5, 11};
    int i = 0;
    
    printf("=== ft_memchr テスト ===\n");
    while (i < 3)
    {
        void *ft_res = ft_memchr(buf, vals[i], lens[i]);
        void *std_res = memchr(buf, vals[i], lens[i]);
        printf("val=%d, len=%zu: ft=%p, std=%p -> %s\n", 
            vals[i], lens[i],
            ft_res, std_res,
            ft_res == std_res ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_memcmp

### 機能
2つのメモリ領域を比較する

### テストケース
- 同じ内容
- 異なる内容
- 部分的に異なる内容

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s1[] = {"Hello", "Hello", "abc"};
    char *s2[] = {"Hello", "World", "xyz"};
    size_t lens[] = {5, 5, 3};
    int i = 0;
    
    printf("=== ft_memcmp テスト ===\n");
    while (i < 3)
    {
        int ft_res = ft_memcmp(s1[i], s2[i], lens[i]);
        int std_res = memcmp(s1[i], s2[i], lens[i]);
        printf("\"%s\" vs \"%s\" (n=%zu): ft=%d, std=%d -> %s\n", 
            s1[i], s2[i], lens[i],
            ft_res, std_res,
            (ft_res == std_res || (ft_res > 0 && std_res > 0) || (ft_res < 0 && std_res < 0)) ? "OK" : "NG");
        i++;
    }
    return (0);
}
```

---

## ft_strlcpy

### 機能
文字列を安全にコピーする（バッファサイズ指定）

### テストケース
- 通常のコピー（期待値：srcの長さ、dstに完全コピー）
- バッファが小さい場合（期待値：srcの長さ、dstは切り詰められる）
- バッファサイズが0の場合（期待値：srcの長さ、dstは変更なし）

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "Hello World";
    size_t src_len = strlen(src);
    
    printf("=== ft_strlcpy テスト ===\n");
    
    // テスト1: 十分なサイズ
    char dst1[20];
    memset(dst1, 'X', 20);
    size_t ret1 = ft_strlcpy(dst1, src, 20);
    printf("Test 1 (size=20): ret=%zu (expected=%zu), dst=\"%s\" -> %s\n",
        ret1, src_len, dst1,
        (ret1 == src_len && strcmp(dst1, src) == 0) ? "OK" : "NG");
    
    // テスト2: 小さいサイズ
    char dst2[20];
    memset(dst2, 'X', 20);
    size_t ret2 = ft_strlcpy(dst2, src, 6);
    printf("Test 2 (size=6): ret=%zu (expected=%zu), dst=\"%s\" (expected=\"Hello\") -> %s\n",
        ret2, src_len, dst2,
        (ret2 == src_len && strcmp(dst2, "Hello") == 0) ? "OK" : "NG");
    
    // テスト3: サイズ0
    char dst3[20];
    memset(dst3, 'X', 20);
    dst3[0] = 'X';
    size_t ret3 = ft_strlcpy(dst3, src, 0);
    printf("Test 3 (size=0): ret=%zu (expected=%zu), dst[0]='%c' (expected='X') -> %s\n",
        ret3, src_len, dst3[0],
        (ret3 == src_len && dst3[0] == 'X') ? "OK" : "NG");
    
    return (0);
}
```

---

## ft_strlcat

### 機能
文字列を安全に連結する（バッファサイズ指定）

### テストケース
- 通常の連結（期待値：dst_len + src_len、文字列が連結される）
- バッファが小さい場合（期待値：size + src_len、文字列は切り詰められる）
- dstがいっぱいの場合（期待値：size + src_len、変更なし）

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *src = " World";
    
    printf("=== ft_strlcat テスト ===\n");
    
    // テスト1: 十分なサイズ
    char dst1[20];
    strcpy(dst1, "Hello");
    size_t ret1 = ft_strlcat(dst1, src, 20);
    printf("Test 1 (size=20): ret=%zu (expected=11), dst=\"%s\" (expected=\"Hello World\") -> %s\n",
        ret1, dst1,
        (ret1 == 11 && strcmp(dst1, "Hello World") == 0) ? "OK" : "NG");
    
    // テスト2: 小さいサイズ
    char dst2[20];
    strcpy(dst2, "Hello");
    size_t ret2 = ft_strlcat(dst2, src, 10);
    printf("Test 2 (size=10): ret=%zu (expected=11), dst=\"%s\" (expected=\"Hello Wor\") -> %s\n",
        ret2, dst2,
        (ret2 == 11 && strcmp(dst2, "Hello Wor") == 0) ? "OK" : "NG");
    
    // テスト3: dstがいっぱい
    char dst3[20];
    strcpy(dst3, "Hello");
    size_t ret3 = ft_strlcat(dst3, src, 6);
    printf("Test 3 (size=6): ret=%zu (expected=12), dst=\"%s\" (expected=\"Hello\") -> %s\n",
        ret3, dst3,
        (ret3 == 12 && strcmp(dst3, "Hello") == 0) ? "OK" : "NG");
    
    return (0);
}
```

---

## ft_calloc

### 機能
メモリを確保してゼロで初期化する

### テストケース
- 通常の確保
- サイズ0の確保
- 大きなサイズの確保

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    size_t counts[] = {10, 0, 100};
    size_t sizes[] = {1, 1, 1};
    int i = 0;
    
    printf("=== ft_calloc テスト ===\n");
    while (i < 3)
    {
        void *ft_ptr = ft_calloc(counts[i], sizes[i]);
        void *std_ptr = calloc(counts[i], sizes[i]);
        
        int match = 1;
        if (counts[i] > 0)
        {
            match = memcmp(ft_ptr, std_ptr, counts[i] * sizes[i]) == 0;
        }
        
        printf("count=%zu, size=%zu: %s\n", 
            counts[i], sizes[i],
            match ? "OK" : "NG");
        
        free(ft_ptr);
        free(std_ptr);
        i++;
    }
    return (0);
}
```

---

## ft_strdup

### 機能
文字列を複製する

### テストケース
- 通常の文字列
- 空文字列
- 長い文字列

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *tests[] = {"Hello", "", "42 Tokyo"};
    int i = 0;
    
    printf("=== ft_strdup テスト ===\n");
    while (i < 3)
    {
        char *ft_res = ft_strdup(tests[i]);
        char *std_res = strdup(tests[i]);
        printf("\"%s\": %s\n", 
            tests[i],
            strcmp(ft_res, std_res) == 0 ? "OK" : "NG");
        free(ft_res);
        free(std_res);
        i++;
    }
    return (0);
}
```

---

## ft_substr

### 機能
文字列の部分文字列を作成する

### テストケース
- 通常の部分文字列
- 開始位置が文字列長を超える場合
- 長さが残りより長い場合

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *str = "Hello World";
    unsigned int starts[] = {0, 6, 20};
    size_t lens[] = {5, 5, 5};
    char *expected[] = {"Hello", "World", ""};
    int i = 0;
    
    printf("=== ft_substr テスト ===\n");
    while (i < 3)
    {
        char *result = ft_substr(str, starts[i], lens[i]);
        printf("start=%u, len=%zu: \"%s\" (expected: \"%s\") -> %s\n", 
            starts[i], lens[i], result, expected[i],
            strcmp(result, expected[i]) == 0 ? "OK" : "NG");
        free(result);
        i++;
    }
    return (0);
}
```

---

## ft_strjoin

### 機能
2つの文字列を連結した新しい文字列を作成する

### テストケース
- 通常の連結
- 空文字列との連結
- 両方が空文字列

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *s1[] = {"Hello", "42", ""};
    char *s2[] = {" World", " Tokyo", ""};
    char *expected[] = {"Hello World", "42 Tokyo", ""};
    int i = 0;
    
    printf("=== ft_strjoin テスト ===\n");
    while (i < 3)
    {
        char *result = ft_strjoin(s1[i], s2[i]);
        printf("\"%s\" + \"%s\" = \"%s\" (expected: \"%s\") -> %s\n", 
            s1[i], s2[i], result, expected[i],
            strcmp(result, expected[i]) == 0 ? "OK" : "NG");
        free(result);
        i++;
    }
    return (0);
}
```

---

## ft_strtrim

### 機能
文字列の前後から指定した文字を削除する

### テストケース
- 前後に削除対象文字がある場合
- 削除対象文字がない場合
- 全て削除対象文字の場合

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *strs[] = {"  Hello  ", "***42***", "abcabc"};
    char *sets[] = {" ", "*", "abc"};
    char *expected[] = {"Hello", "42", ""};
    int i = 0;
    
    printf("=== ft_strtrim テスト ===\n");
    while (i < 3)
    {
        char *result = ft_strtrim(strs[i], sets[i]);
        printf("\"%s\" trim '%s' = \"%s\" (expected: \"%s\") -> %s\n", 
            strs[i], sets[i], result, expected[i],
            strcmp(result, expected[i]) == 0 ? "OK" : "NG");
        free(result);
        i++;
    }
    return (0);
}
```

---

## ft_split

### 機能
文字列を区切り文字で分割する

### テストケース
- 通常の分割
- 連続する区切り文字
- 区切り文字がない場合

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *str1 = "Hello World 42";
    char *str2 = "a,,b,,c";
    char *str3 = "NoSpace";
    
    printf("=== ft_split テスト ===\n");
    
    // テスト1
    char **result1 = ft_split(str1, ' ');
    printf("Test 1: \"%s\" split by ' ':\n", str1);
    int i = 0;
    while (result1[i])
    {
        printf("  [%d]: \"%s\"\n", i, result1[i]);
        free(result1[i]);
        i++;
    }
    free(result1);
    
    // テスト2
    char **result2 = ft_split(str2, ',');
    printf("Test 2: \"%s\" split by ',':\n", str2);
    i = 0;
    while (result2[i])
    {
        printf("  [%d]: \"%s\"\n", i, result2[i]);
        free(result2[i]);
        i++;
    }
    free(result2);
    
    // テスト3
    char **result3 = ft_split(str3, ' ');
    printf("Test 3: \"%s\" split by ' ':\n", str3);
    i = 0;
    while (result3[i])
    {
        printf("  [%d]: \"%s\"\n", i, result3[i]);
        free(result3[i]);
        i++;
    }
    free(result3);
    
    return (0);
}
```

---

## ft_itoa

### 機能
整数を文字列に変換する

### テストケース
- 正の数
- 負の数
- 0
- INT_MIN, INT_MAX

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int tests[] = {42, -42, 0, INT_MIN, INT_MAX};
    char *expected[] = {"42", "-42", "0", "-2147483648", "2147483647"};
    int i = 0;
    
    printf("=== ft_itoa テスト ===\n");
    while (i < 5)
    {
        char *result = ft_itoa(tests[i]);
        printf("%d -> \"%s\" (expected: \"%s\") -> %s\n", 
            tests[i], result, expected[i],
            strcmp(result, expected[i]) == 0 ? "OK" : "NG");
        free(result);
        i++;
    }
    return (0);
}
```

---

## ft_strmapi

### 機能
文字列の各文字に関数を適用した新しい文字列を作成する

### テストケース
- 文字を変換する関数
- インデックスを使用する関数

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char test_func(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

char index_func(unsigned int i, char c)
{
    return (c + i);
}

int main(void)
{
    char *str = "hello";
    
    printf("=== ft_strmapi テスト ===\n");
    
    // テスト1: 大文字変換
    char *result1 = ft_strmapi(str, test_func);
    printf("Test 1: \"%s\" -> \"%s\" (expected: \"HELLO\") -> %s\n", 
        str, result1,
        strcmp(result1, "HELLO") == 0 ? "OK" : "NG");
    free(result1);
    
    // テスト2: インデックス加算
    char *result2 = ft_strmapi("aaaaa", index_func);
    printf("Test 2: \"aaaaa\" -> \"%s\" (expected: \"abcde\") -> %s\n", 
        result2,
        strcmp(result2, "abcde") == 0 ? "OK" : "NG");
    free(result2);
    
    return (0);
}
```

---

## ft_striteri

### 機能
文字列の各文字に関数を適用する（元の文字列を変更）

### テストケース
- 文字を変換する関数
- インデックスを使用する関数

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <string.h>

void test_func(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

void index_func(unsigned int i, char *c)
{
    *c = *c + i;
}

int main(void)
{
    char str1[] = "hello";
    char str2[] = "aaaaa";
    
    printf("=== ft_striteri テスト ===\n");
    
    // テスト1: 大文字変換
    printf("Test 1: Before: \"%s\"\n", str1);
    ft_striteri(str1, test_func);
    printf("        After:  \"%s\" (expected: \"HELLO\") -> %s\n", 
        str1,
        strcmp(str1, "HELLO") == 0 ? "OK" : "NG");
    
    // テスト2: インデックス加算
    printf("Test 2: Before: \"%s\"\n", str2);
    ft_striteri(str2, index_func);
    printf("        After:  \"%s\" (expected: \"abcde\") -> %s\n", 
        str2,
        strcmp(str2, "abcde") == 0 ? "OK" : "NG");
    
    return (0);
}
```

---

## ft_putchar_fd

### 機能
文字をファイルディスクリプタに出力する

### テストケース
- 標準出力への出力
- 標準エラー出力への出力

### メインコード
```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    printf("=== ft_putchar_fd テスト ===\n");
    
    printf("Test 1 (stdout): ");
    ft_putchar_fd('A', 1);
    ft_putchar_fd('\n', 1);
    
    printf("Test 2 (stderr): ");
    ft_putchar_fd('B', 2);
    ft_putchar_fd('\n', 2);
    
    printf("Test 3 (multiple): ");
    ft_putchar_fd('4', 1);
    ft_putchar_fd('2', 1);
    ft_putchar_fd('\n', 1);
    
    return (0);
}
```

---

## ft_putstr_fd

### 機能
文字列をファイルディスクリプタに出力する

### テストケース
- 標準出力への出力
- 空文字列の出力

### メインコード
```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    printf("=== ft_putstr_fd テスト ===\n");
    
    printf("Test 1 (normal): ");
    ft_putstr_fd("Hello World", 1);
    ft_putchar_fd('\n', 1);
    
    printf("Test 2 (empty): ");
    ft_putstr_fd("", 1);
    ft_putstr_fd("[empty]\n", 1);
    
    printf("Test 3 (stderr): ");
    ft_putstr_fd("Error message", 2);
    ft_putchar_fd('\n', 2);
    
    return (0);
}
```

---

## ft_putendl_fd

### 機能
文字列と改行をファイルディスクリプタに出力する

### テストケース
- 標準出力への出力
- 複数行の出力

### メインコード
```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    printf("=== ft_putendl_fd テスト ===\n");
    
    printf("Test 1:\n");
    ft_putendl_fd("Line 1", 1);
    ft_putendl_fd("Line 2", 1);
    ft_putendl_fd("Line 3", 1);
    
    printf("Test 2 (stderr):\n");
    ft_putendl_fd("Error line", 2);
    
    return (0);
}
```

---

## ft_putnbr_fd

### 機能
整数をファイルディスクリプタに出力する

### テストケース
- 正の数
- 負の数
- 0
- INT_MIN, INT_MAX

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("=== ft_putnbr_fd テスト ===\n");
    
    printf("Test 1 (positive): ");
    ft_putnbr_fd(42, 1);
    ft_putchar_fd('\n', 1);
    
    printf("Test 2 (negative): ");
    ft_putnbr_fd(-42, 1);
    ft_putchar_fd('\n', 1);
    
    printf("Test 3 (zero): ");
    ft_putnbr_fd(0, 1);
    ft_putchar_fd('\n', 1);
    
    printf("Test 4 (INT_MIN): ");
    ft_putnbr_fd(INT_MIN, 1);
    ft_putchar_fd('\n', 1);
    
    printf("Test 5 (INT_MAX): ");
    ft_putnbr_fd(INT_MAX, 1);
    ft_putchar_fd('\n', 1);
    
    return (0);
}
```

---

## ft_lstnew

### 機能
新しいリストノードを作成する（libft独自関数）

### テストケース
- 整数データを持つノード（期待値：content=データ、next=NULL）
- 文字列データを持つノード（期待値：content=データ、next=NULL）
- NULLデータを持つノード（期待値：content=NULL、next=NULL）

### メインコード
```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    printf("=== ft_lstnew テスト ===\n");
    
    // テスト1: 整数
    int num = 42;
    t_list *node1 = ft_lstnew(&num);
    printf("Test 1: content=%d, next=%p -> %s\n", 
        *(int *)node1->content,
        (void *)node1->next,
        (*(int *)node1->content == 42 && node1->next == NULL) ? "OK" : "NG");
    free(node1);
    
    // テスト2: 文字列
    char *str = "Hello";
    t_list *node2 = ft_lstnew(str);
    printf("Test 2: content=\"%s\", next=%p -> %s\n", 
        (char *)node2->content,
        (void *)node2->next,
        (node2->content == str && node2->next == NULL) ? "OK" : "NG");
    free(node2);
    
    // テスト3: NULL
    t_list *node3 = ft_lstnew(NULL);
    printf("Test 3: content=%p, next=%p -> %s\n", 
        node3->content,
        (void *)node3->next,
        (node3->content == NULL && node3->next == NULL) ? "OK" : "NG");
    free(node3);
    
    return (0);
}
```

---

## ft_lstadd_front

### 機能
リストの先頭にノードを追加する（libft独自関数）

### テストケース
- 空リストへの追加（期待値：lst=新ノード）
- 既存リストへの追加（期待値：lst=新ノード、新ノード->next=旧先頭）

### メインコード
```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    printf("=== ft_lstadd_front テスト ===\n");
    
    // テスト1: 空リスト
    t_list *lst = NULL;
    t_list *node1 = ft_lstnew("First");
    ft_lstadd_front(&lst, node1);
    printf("Test 1: %s\n", 
        (lst == node1) ? "OK" : "NG");
    
    // テスト2: 既存リスト
    t_list *node2 = ft_lstnew("Second");
    ft_lstadd_front(&lst, node2);
    printf("Test 2: %s\n", 
        (lst == node2 && lst->next == node1) ? "OK" : "NG");
    
    // クリーンアップ
    free(node1);
    free(node2);
    
    return (0);
}
```

---

## ft_lstsize

### 機能
リストのノード数を返す（libft独自関数）

### テストケース
- 空リスト（期待値：0）
- 1つのノード（期待値：1）
- 複数のノード（期待値：ノード数）

### メインコード
```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    printf("=== ft_lstsize テスト ===\n");
    
    // テスト1: 空リスト
    t_list *lst = NULL;
    printf("Test 1 (empty): %d -> %s\n", 
        ft_lstsize(lst),
        ft_lstsize(lst) == 0 ? "OK" : "NG");
    
    // テスト2: 1ノード
    t_list *node1 = ft_lstnew("1");
    lst = node1;
    printf("Test 2 (1 node): %d -> %s\n", 
        ft_lstsize(lst),
        ft_lstsize(lst) == 1 ? "OK" : "NG");
    
    // テスト3: 3ノード
    t_list *node2 = ft_lstnew("2");
    t_list *node3 = ft_lstnew("3");
    node1->next = node2;
    node2->next = node3;
    printf("Test 3 (3 nodes): %d -> %s\n", 
        ft_lstsize(lst),
        ft_lstsize(lst) == 3 ? "OK" : "NG");
    
    // クリーンアップ
    free(node1);
    free(node2);
    free(node3);
    
    return (0);
}
```

---

## ft_lstlast

### 機能
リストの最後のノードを返す（libft独自関数）

### テストケース
- 空リスト（期待値：NULL）
- 1つのノード（期待値：そのノード）
- 複数のノード（期待値：最後のノード）

### メインコード
```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    printf("=== ft_lstlast テスト ===\n");
    
    // テスト1: 空リスト
    t_list *lst = NULL;
    printf("Test 1 (empty): %p -> %s\n", 
        (void *)ft_lstlast(lst),
        ft_lstlast(lst) == NULL ? "OK" : "NG");
    
    // テスト2: 1ノード
    t_list *node1 = ft_lstnew("1");
    lst = node1;
    printf("Test 2 (1 node): %s\n", 
        ft_lstlast(lst) == node1 ? "OK" : "NG");
    
    // テスト3: 3ノード
    t_list *node2 = ft_lstnew("2");
    t_list *node3 = ft_lstnew("3");
    node1->next = node2;
    node2->next = node3;
    printf("Test 3 (3 nodes): %s\n", 
        ft_lstlast(lst) == node3 ? "OK" : "NG");
    
    // クリーンアップ
    free(node1);
    free(node2);
    free(node3);
    
    return (0);
}
```

---

## ft_lstadd_back

### 機能
リストの最後にノードを追加する（libft独自関数）

### テストケース
- 空リストへの追加（期待値：lst=新ノード）
- 既存リストへの追加（期待値：最後のノード->next=新ノード）

### メインコード
```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    printf("=== ft_lstadd_back テスト ===\n");
    
    // テスト1: 空リスト
    t_list *lst = NULL;
    t_list *node1 = ft_lstnew("First");
    ft_lstadd_back(&lst, node1);
    printf("Test 1: %s\n", 
        (lst == node1) ? "OK" : "NG");
    
    // テスト2: 既存リスト
    t_list *node2 = ft_lstnew("Second");
    ft_lstadd_back(&lst, node2);
    printf("Test 2: %s\n", 
        (lst->next == node2) ? "OK" : "NG");
    
    // テスト3: さらに追加
    t_list *node3 = ft_lstnew("Third");
    ft_lstadd_back(&lst, node3);
    printf("Test 3: %s\n", 
        (node2->next == node3) ? "OK" : "NG");
    
    // クリーンアップ
    free(node1);
    free(node2);
    free(node3);
    
    return (0);
}
```

---

## ft_lstdelone

### 機能
1つのノードを削除する（libft独自関数）

### テストケース
- 動的に確保されたコンテンツを持つノード（期待値：メモリ解放、クラッシュしない）
- del関数の動作確認（期待値：del関数が呼ばれる）

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void del(void *content)
{
    free(content);
}

int main(void)
{
    printf("=== ft_lstdelone テスト ===\n");
    
    // テスト: ノードとコンテンツの削除
    char *str = malloc(10);
    if (str)
    {
        strcpy(str, "Test");
        t_list *node = ft_lstnew(str);
        printf("Test 1: Node created\n");
        ft_lstdelone(node, del);
        printf("Test 1: Node deleted -> OK (no crash)\n");
    }
    
    return (0);
}
```

---

## ft_lstclear

### 機能
リスト全体を削除する（libft独自関数）

### テストケース
- 複数ノードのリスト（期待値：全ノード削除、クラッシュしない）
- 削除後リストがNULLになるか確認（期待値：lst=NULL）

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void del(void *content)
{
    free(content);
}

int main(void)
{
    printf("=== ft_lstclear テスト ===\n");
    
    // テスト: 3ノードのリスト削除
    t_list *node1 = ft_lstnew(malloc(10));
    t_list *node2 = ft_lstnew(malloc(10));
    t_list *node3 = ft_lstnew(malloc(10));
    node1->next = node2;
    node2->next = node3;
    
    t_list *lst = node1;
    printf("Test 1: List created with 3 nodes\n");
    ft_lstclear(&lst, del);
    printf("Test 1: List cleared, lst=%p -> %s\n", 
        (void *)lst,
        lst == NULL ? "OK" : "NG");
    
    return (0);
}
```

---

## ft_lstiter

### 機能
リストの各ノードに関数を適用する（libft独自関数）

### テストケース
- 各ノードのコンテンツを表示する関数（期待値：全ノード処理）
- 各ノードのコンテンツを変更する関数（期待値：値が変更される）

### メインコード
```c
#include "libft.h"
#include <stdio.h>

void print_content(void *content)
{
    printf("  Content: %s\n", (char *)content);
}

void add_one(void *content)
{
    (*(int *)content)++;
}

int main(void)
{
    printf("=== ft_lstiter テスト ===\n");
    
    // テスト1: 表示
    t_list *node1 = ft_lstnew("First");
    t_list *node2 = ft_lstnew("Second");
    t_list *node3 = ft_lstnew("Third");
    node1->next = node2;
    node2->next = node3;
    
    printf("Test 1 (print):\n");
    ft_lstiter(node1, print_content);
    
    // テスト2: 値の変更
    int a = 1, b = 2, c = 3;
    t_list *lst2 = ft_lstnew(&a);
    t_list *lst3 = ft_lstnew(&b);
    t_list *lst4 = ft_lstnew(&c);
    lst2->next = lst3;
    lst3->next = lst4;
    
    printf("Test 2 (add_one): Before: %d, %d, %d\n", a, b, c);
    ft_lstiter(lst2, add_one);
    printf("Test 2 (add_one): After:  %d, %d, %d -> %s\n", 
        a, b, c,
        (a == 2 && b == 3 && c == 4) ? "OK" : "NG");
    
    // クリーンアップ
    free(node1);
    free(node2);
    free(node3);
    free(lst2);
    free(lst3);
    free(lst4);
    
    return (0);
}
```

---

## ft_lstmap

### 機能
リストの各ノードに関数を適用した新しいリストを作成する（libft独自関数）

### テストケース
- 変換関数を適用した新しいリスト（期待値：元のリストと同じ長さの新リスト）
- メモリ確保失敗時の処理（期待値：NULLを返す、メモリリークなし）

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *duplicate_str(void *content)
{
    char *str = (char *)content;
    return (strdup(str));
}

void del(void *content)
{
    free(content);
}

int main(void)
{
    printf("=== ft_lstmap テスト ===\n");
    
    // テスト: 文字列の複製
    t_list *node1 = ft_lstnew("First");
    t_list *node2 = ft_lstnew("Second");
    t_list *node3 = ft_lstnew("Third");
    node1->next = node2;
    node2->next = node3;
    
    t_list *new_lst = ft_lstmap(node1, duplicate_str, del);
    
    printf("Test 1: Original list:\n");
    t_list *tmp = node1;
    while (tmp)
    {
        printf("  %s\n", (char *)tmp->content);
        tmp = tmp->next;
    }
    
    printf("Test 1: New list:\n");
    tmp = new_lst;
    int count = 0;
    while (tmp)
    {
        printf("  %s\n", (char *)tmp->content);
        tmp = tmp->next;
        count++;
    }
    
    printf("Test 1: Count=%d -> %s\n", 
        count,
        count == 3 ? "OK" : "NG");
    
    // クリーンアップ
    ft_lstclear(&new_lst, del);
    free(node1);
    free(node2);
    free(node3);
    
    return (0);
}
```

---

## ft_long_atoi

### 機能
文字列をlong型の整数に変換する（libft独自関数）

### テストケース
- 正の数（期待値：正しい数値）
- 負の数（期待値：正しい数値）
- LONG_MAX（期待値：LONG_MAX）
- LONG_MIN（期待値：LONG_MIN）

### メインコード
```c
#include "libft.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("=== ft_long_atoi テスト ===\n");
    
    // テスト1: 正の数
    long result1 = ft_long_atoi("42");
    printf("Test 1: \"42\" -> %ld (expected=42) -> %s\n",
        result1,
        result1 == 42 ? "OK" : "NG");
    
    // テスト2: 負の数
    long result2 = ft_long_atoi("-42");
    printf("Test 2: \"-42\" -> %ld (expected=-42) -> %s\n",
        result2,
        result2 == -42 ? "OK" : "NG");
    
    // テスト3: LONG_MAX
    long result3 = ft_long_atoi("9223372036854775807");
    printf("Test 3: \"9223372036854775807\" -> %ld (expected=LONG_MAX) -> %s\n",
        result3,
        result3 == LONG_MAX ? "OK" : "NG");
    
    // テスト4: LONG_MIN
    long result4 = ft_long_atoi("-9223372036854775808");
    printf("Test 4: \"-9223372036854775808\" -> %ld (expected=LONG_MIN) -> %s\n",
        result4,
        result4 == LONG_MIN ? "OK" : "NG");
    
    // テスト5: オーバーフロー（正）
    long result5 = ft_long_atoi("9999999999999999999");
    printf("Test 5: \"9999999999999999999\" (overflow) -> %ld (expected=LONG_MAX) -> %s\n",
        result5,
        result5 == LONG_MAX ? "OK" : "NG");
    
    return (0);
}
```

---

