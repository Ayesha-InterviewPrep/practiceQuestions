struct node{
    char var;
    int count;
    node * link;
};

node * head1;

class Solution {
public:
    bool isAnagram(string s, string t) {
        head1 =NULL;
        if (s.length() != t.length()){
            return 0;
        }
        else if (s.length() <=1 && t.length()<=1){
            if (s ==t) return 1;
            else return 0;
        }
        int i;
        
        for (i =0; i<s.length(); i++){
            insert(i,s[i], head1);
        }
        bool found;
        for (i =0; i<t.length(); i++){
            found = find_alph(t[i]);
            if (found != 1){
                return 0;
            }
        }
        found = all_zeroes(head1);
        if (found != 1){
            return 0;
        }
        else  return 1;;
    }
    
    void insert (int index, char alph, node* &head){
       // index = index-1;
        
        node * temp = new(node);
        node * prev = head;
        
        temp->var = alph;
        temp->count = 1;
        temp->link = NULL;
        if (index==0){
            head = temp;
            return;
        }
        if (prev !=NULL){
            if (prev->var != alph) ;
            else if (prev->var == alph){
                prev->count +=1;
                return;}
        }
        node * next = head->link;
        if (index > 0){
            while (next !=NULL){
                if (prev->var != alph) {
                    prev = next;
                    next = next->link;}
                else {
                    prev->count +=1;
                    return;}
            }
            if (prev->var == alph){
                prev->count +=1;
                return;}
            prev->link = temp;
            return;
        }
    }
    
    bool find_alph(char alph){
        node * prev = head1;
        if (prev !=NULL){
            if (prev->var != alph) ;
            else if (prev->var == alph){
                prev->count -=1;
                return 1;}
        }
        node * next = head1->link;
     
        while (next !=NULL ){
            char k = prev->var;
            if (prev->var != alph) {
                prev = next;
                next = next->link;
            }
            else {
                prev->count -=1;
                if (prev->count >=0) return 1;
                else return 0;}
        }
        if (prev->var == alph){
            prev->count -=1;
            if (prev->count >=0) return 1;
            else return 0;}
        else return 0;
    }
    bool all_zeroes(node *head){
        node * temp = head;
        while (temp !=NULL) {
            if (temp->count != 0) return 0;
            else   temp = temp->link;
        }
        return 1;
    }
};
