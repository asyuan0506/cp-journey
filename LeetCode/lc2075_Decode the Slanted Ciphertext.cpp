class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        const int col = encodedText.size() / rows;
        string plain_text = "";
        // for (int d = 0; d < col; d++) // Diagonal
        // {
        //     for (int r = 0; r < rows; r++)
        //     {
        //         if (r + d >= col) break;
        //         plain_text += encodedText[r * col + r + d]; //encodedText[r][r + d];
        //     }
        // }
        // bool trailing_spaces = true;
        // string ans = "";
        // for (int i = plain_text.size() - 1; i >= 0; i--)
        // {
        //     if (plain_text[i] != ' ')
        //         trailing_spaces = false;
        //     if (trailing_spaces)
        //         continue;
        //     ans += plain_text[i];
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;
        
        // Do it from the back will be faster
        bool trailing_spaces = true; 
        for (int d = col - 1; d >= 0; d--)
        {
            for (int r = rows - 1; r >= 0; r--)
            {
                if (r + d >= col) continue;

                char c = encodedText[r * col + r + d];
                if (c != ' ')
                    trailing_spaces = false;
                if (trailing_spaces) continue;

                plain_text += c;
            }
        }
        reverse(plain_text.begin(), plain_text.end());
        return plain_text;
    }
};