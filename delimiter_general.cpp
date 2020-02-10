   vector<string> delimiter_general(string path) {
        string temp;
        //vector to which contains extracted directory names
        vector<string> v;
        path = path + '/';
        
        for(int i=0; i<path.length();i++){
            if(path[i] == '/'){
                if(temp.length()!=0) {
                    v.push_back(temp);
                    temp.erase();
                }
            }
            else {
                temp=temp+path[i];
            }
        }
	return v;
}
