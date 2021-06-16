#include<bits/stdc++.h>
using namespace std;

/*
IP: "ababc"
idx 0: PP []					S [a]
idx 1: PP [a]					S [b, ab]
idx 2: PP [a, ab]				S [a, ba, aba]
idx 3: PP [a, ab, aba]			S [b, ab, bab, abab]
idx 4: PP [a, ab, aba, abab]	S [c, bc, abc, babc, ababc]

LPS: [0, 0, 1, 2, 0]

IP: "abacabad"
idx 0: PP []											S [a]
idx 1: PP [a]											S [b, ab]
idx 2: PP [a, ab]										S [a, ba, aba]
idx 3: PP [a, ab, aba]									S [c, ac, bac, abac]
idx 4: PP [a, ab, aba, abac]							S [a, ca, aca, baca, abaca]
idx 5: PP [a, ab, aba, abac, abaca]						S [b, ab, cab, acab, bacab, abacab]
idx 6: PP [a, ab, aba, abac, abaca, abacab]				S [a, ba, aba, caba, acaba, bacaba, abacaba]
idx 7: PP [a, ab, aba, abac, abaca, abacab, abacaba]	S [d, ad, bad, abad, cabad, acabad, bacabad, abacabad]

LPS: [0, 0, 1, 0, 1, 2, 3, 0]
*/