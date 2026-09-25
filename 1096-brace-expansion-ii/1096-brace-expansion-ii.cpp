class Solution {
public:

    set<string> parseUnion(string &s, int &i) {

        set<string> result = parseConcat(s, i);

        while (i < s.size() && s[i] == ',') {

            i++; // skip ','

            set<string> next = parseConcat(s, i);

            result.insert(next.begin(), next.end());
        }

        return result;
    }

    set<string> parseConcat(string &s, int &i) {

        set<string> result;
        result.insert("");

        while (i < s.size() &&
               s[i] != '}' &&
               s[i] != ',') {

            set<string> cur;

            if (s[i] >= 'a' && s[i] <= 'z') {

                cur.insert(string(1, s[i]));
                i++;
            }

            else if (s[i] == '{') {

                i++; // skip '{'

                cur = parseUnion(s, i);

                i++; // skip '}'
            }

            // Cartesian product = concatenation
            set<string> combined;

            for (const string &a : result) {
                for (const string &b : cur) {
                    combined.insert(a + b);
                }
            }

            result = combined;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parseUnion(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};