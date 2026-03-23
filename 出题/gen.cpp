#include <bits/stdc++.h>
using namespace std;

int main() {
    // ====== Case 6: 1000-char even palindrome, all alnum (lowercase + digits mixed) ======
    // Tests: max-length palindrome, full O(n^2) computation
    // Answer: entire 1000-char string
    {
        string half;
        for (int i = 0; i < 500; i++) {
            if (i % 5 == 0) half += ('0' + i % 10);
            else half += ('a' + i % 26);
        }
        string pal = half + string(half.rbegin(), half.rend());
        ofstream out("data/6.in");
        out << pal << "\n0\n";
    }

    // ====== Case 7: 1000 chars, sparse alnum among punctuation ======
    // 100 alnum chars at positions 0,10,20,...,990 forming a 100-char palindrome
    // Rest filled with varied non-alnum chars
    // Tests: S-to-T mapping at scale, non-alnum preservation in output
    // Answer: S[0..990] (991 chars including all punctuation)
    {
        string half;
        for (int i = 0; i < 50; i++) half += ('a' + i % 26);
        string pal = half + string(half.rbegin(), half.rend()); // 100-char palindrome

        string puncts = " ,.;!?-+=~@$%^&*(){}";  // 21 chars, no # to avoid ### issues
        string s(1000, '.');
        for (int i = 0; i < 1000; i++) {
            s[i] = puncts[i % puncts.size()];
        }
        for (int i = 0; i < 100; i++) {
            s[i * 10] = pal[i];
        }
        ofstream out("data/7.in");
        out << s << "\n0\n";
    }

    // ====== Case 8: Multi-line with NOISE:/### cleaning, palindrome spans lines ======
    // 4 lines, each contributes 250 chars after cleaning. Total S = 1000.
    // 400-char palindrome at positions 300-699, spanning lines 2-3.
    // Tests: cleaning rules at scale + cross-line palindrome
    {
        string base;
        for (int i = 0; i < 300; i++) base += ('a' + (i * 7) % 26);
        string half_pal;
        for (int i = 0; i < 200; i++) half_pal += ('a' + (i * 3 + 1) % 26);
        string pal = half_pal + string(half_pal.rbegin(), half_pal.rend());
        string suffix;
        for (int i = 0; i < 300; i++) suffix += ('a' + (i * 11 + 5) % 26);
        string full = base + pal + suffix;

        string line1 = "NOISE: " + full.substr(0, 250) + " ###";
        string line2 = full.substr(250, 250);
        string line3 = "noise:  " + full.substr(500, 250) + "  ###";
        string line4 = full.substr(750, 250);

        ofstream out("data/8.in");
        out << line1 << "\n" << line2 << "\n" << line3 << "\n" << line4 << "\n0\n";
    }

    // ====== Case 9: Case-sensitivity trap ======
    // first_half (500 lowercase) + second_half (reversed uppercase)
    // Case-insensitively: entire 1000-char string is a palindrome!
    // Case-sensitively: max palindrome in filler = 1
    // Plant a 51-char mixed-case palindrome at position 475
    // Tests: case sensitivity correctness
    // Wrong (case-insensitive) answer: 1000. Correct answer: 51 chars.
    {
        string first_half;
        for (int i = 0; i < 500; i++) first_half += ('a' + i % 26);
        string rev_first(first_half.rbegin(), first_half.rend());
        string second_half;
        for (char c : rev_first) second_half += toupper((unsigned char)c);

        string s = first_half + second_half;

        // 51-char mixed-case palindrome: "AbCdEfGhIjKlMnOpQrStUvWxYzYxWvUtSrQpOnMlKjIhGfEdCbA"
        string pal_half = "AbCdEfGhIjKlMnOpQrStUvWxY"; // 25 chars
        string pal = pal_half + "z" + string(pal_half.rbegin(), pal_half.rend()); // 51 chars

        for (int i = 0; i < 51; i++) s[475 + i] = pal[i];

        ofstream out("data/9.in");
        out << s << "\n0\n";
    }

    // ====== Case 10: Tie-breaking, two equal-length palindromes ======
    // Filler: "abc..." cycling (max palindrome = 1)
    // Palindrome 1 (digits, len 60) at position 100
    // Palindrome 2 (uppercase, len 60) at position 700
    // Both can't extend (different char types at boundaries)
    // Tests: earliest-start tie-breaking
    // Answer: palindrome 1 (the digit one at position 100)
    {
        auto make_filler = [](int len, int offset) {
            string s;
            for (int i = 0; i < len; i++) s += ('a' + (i + offset) % 26);
            return s;
        };

        string half_p1;
        for (int i = 0; i < 30; i++) half_p1 += ('0' + i % 10);
        string p1 = half_p1 + string(half_p1.rbegin(), half_p1.rend());

        string half_p2;
        for (int i = 0; i < 30; i++) half_p2 += ('A' + i % 26);
        string p2 = half_p2 + string(half_p2.rbegin(), half_p2.rend());

        string s = make_filler(100, 0) + p1 + make_filler(540, 3) + p2 + make_filler(240, 7);

        ofstream out("data/10.in");
        out << s << "\n0\n";
    }

    cout << "All 5 large test cases generated!\n";
    return 0;
}
