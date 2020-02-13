class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack <int> round_valid_score;
        int i=0, score1=0, score2=0;
        int num =0, sum=0;
        while (i<ops.size()){
            //Add previous two rounds valid score
            if (ops.at(i) == "+") {
                score1 = round_valid_score.top();
                round_valid_score.pop();
                score2 = round_valid_score.top();
                round_valid_score.push(score1);
                round_valid_score.push(score1+score2);
                sum+= score1+score2;
            }//Removing illegal score
            else if (ops.at(i) == "C"){
                sum -= round_valid_score.top();
                round_valid_score.pop();
            }//Doubling the previous score and adding it
            else if (ops.at(i) == "D"){
                sum += (round_valid_score.top() *2);
                round_valid_score.push(round_valid_score.top() *2);
            }//Number extraction and adding it
            else {
                num = stoi(ops.at(i));
                round_valid_score.push(num);
                sum+=num;
            }
            i++;
        }
        return sum;
    }
};
