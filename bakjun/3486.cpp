/*The Antique Comedians of Malidinesia prefer comedies to tragedies. Unfortunately, most of the ancient plays are tragedies. Therefore the dramatic advisor of ACM has decided to transfigure some tragedies into comedies. Obviously, this work is very hard because the basic sense of the play must be kept intact, although all the things change to their opposites. For example the numbers: if any number appears in the tragedy, it must be converted to its reversed form before being accepted into the comedy play.

Reversed number is a number written in arabic numerals but the order of digits is reversed. The first digit becomes last and vice versa. For example, if the main hero had 1245 strawberries in the tragedy, he has 5421 of them now. Note that all the leading zeros are omitted. That means if the number ends with a zero, the zero is lost by reversing (e.g. 1200 gives 21). Also note that the reversed number never has any trailing zeros.

ACM needs to calculate with reversed numbers. Your task is to add two reversed numbers and output their reversed sum. Of course, the result is not unique because any particular number is a reversed form of several numbers (e.g. 21 could be 12, 120 or 1200 before reversing). Thus we must assume that no zeros were lost by reversing (e.g. assume that the original number was 12).*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

string reversed_sum(string a, string b)
{
    string::iterator point_a = a.begin();
    string::iterator point_b = b.begin();
    int power = 0;
    int result = 0;

    while (true)
    {
        if (point_a != a.end() && point_b != b.end())
        {
            result += ((*point_a - '0') + (*point_b - '0')) * pow(10, power++);
            point_a++;
            point_b++;
        }
        else if (point_a == a.end() && point_b != b.end())
        {
            result += (*point_b - '0') * pow(10, power++);
            *point_b++;
        }
        else if (point_b == b.end() && point_a != a.end())
        {
            result += (*point_a - '0') * pow(10, power++);
            *point_a++;
        }
        else
        {
            break;
        }
    }

    string output = to_string(result);
    string answer;
    bool meet_non_zero = false;
    for (string::reverse_iterator i = output.rbegin(); i != output.rend(); ++i)
    {
        if (*i == '0' && !meet_non_zero)
            continue;
        meet_non_zero = true;
        answer += *i;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<string> input;
        string temp, temp1;
        cin >> temp >> temp1;
        input.insert(input.end(), temp);
        input.insert(input.end(), temp1);
        string output = reversed_sum(input[0], input[1]);
        cout << output << '\n';
    }

    return 0;
}