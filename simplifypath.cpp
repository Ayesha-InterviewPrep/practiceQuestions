class Solution {
public:
    string simplifyPath(string path) {
        string temp;
        //stack to hold inorder the directory names and strings ("..", ".") 
        stack <string> directory;
        //vector to which contains extracted directory names
        vector<string> v;
        path = path + '/';
        
        for(int i=0; i<path.length();i++){
            if(path[i] == '/'){
                if(temp.length()!=0) {
                    v.push_back(temp);
                    temp.erase ();
                }
            }
            else {
                temp=temp+path[i];
            }
        }
        
        for(int i =0; i<v.size(); i++){
            //To eliminate pop operation when the stack is empty
            if (!directory.empty() && v.at(i) == ".."){
                directory.pop();
            }
            //Dont to push string ".." and "." on the stack
            else if (v.at(i) != ".." && v.at(i) != "."){
                directory.push(v.at(i));
            }
        }
        temp.erase (temp.begin(), temp.end());
        while(!directory.empty()){
            //Construct the string in the reverse order with the pop operation
            temp='/' + directory.top() +temp;
            directory.pop();
        }
        if (temp!="\0")
            return temp;
        else return "/";
    }
};
