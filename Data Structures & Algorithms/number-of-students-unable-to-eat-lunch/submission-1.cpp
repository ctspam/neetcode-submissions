class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int wantCircle = 0;   // count of students wanting type 0
    int wantSquare = 0;   // count of students wanting type 1

    // step 1: count preferences
    for (int s : students) {
        // increment wantCircle or wantSquare based on s
        if(s ==1)
        {
            ++wantSquare;
        }
        else
        {
        ++wantCircle;
        }
    }

    // step 2: process the stack top to bottom
    for (int i = 0; i < sandwiches.size(); ++i) {
        // if this sandwich is type 0 and wantCircle > 0 → someone eats it, wantCircle--
        if(sandwiches[i] == 0 and wantCircle > 0)
        {
            --wantCircle;
        }
        // else if type 1 and wantSquare > 0 → wantSquare--
        else if(sandwiches[i] == 1 and wantSquare > 0)
        {
            --wantSquare;
        }
        // else → nobody wants it, everyone left is stuck: return wantCircle + wantSquare
        else
        {
            return wantCircle + wantSquare;
        }
    }

    return 0;   // all sandwiches consumed → everyone ate
}
};