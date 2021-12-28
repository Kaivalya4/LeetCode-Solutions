class Solution {
public:
    ///whenver number becomes divisible by 10 => increment count of trailing zero by 1
    ///whenver suff >=1e5 . do modulo to get last 5 digit
    ///whenver pre >=1e5 . divide by 10 to maintain the first 5 digit
    string abbreviateProduct(int left, int right) {
        
    long long suff = 1, c = 0, max_suff = 10000000000;
    double pref = 1.0, max_pref = 10000;
    bool over = false;
    for (int i = left; i <= right; ++i) {
        pref *= i;
        suff *= i;
        while (pref >= 100000)
            pref /= 10;
        while (suff % 10 == 0) {
            suff /= 10;
            ++c;
        }
        over |= suff >= max_suff;
        suff %= max_suff;
    }
    auto s = to_string(suff);
        cout << s << endl;
    return (!over ? s : to_string((int)pref) + "..." + s.substr(s.size() - 5)) + "e" + to_string(c);
    } 
};