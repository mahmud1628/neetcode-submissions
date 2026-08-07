struct node {
    int val;
    node * next;
    node() {
        next = nullptr;
    }
    node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class LinkedList {
    node * head;
public:
    LinkedList() {
        head = new node();
    }

    int get(int index) {
        node * temp = head;
        index++;
        while(index--) {
            temp = temp->next;
            if(temp == nullptr) 
                return -1;
        }
        return temp->val;
    }

    void insertHead(int val) {
        node * temp = head->next;
        head->next = new node(val);
        head->next->next = temp;
    }
    
    void insertTail(int val) {
        node * temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = new node(val);
    }

    bool remove(int index) {
        node * prev = head;
        node * curr = head->next;
        while(index--) {
            if(curr == nullptr) return false;
            curr = curr->next;
            prev = prev->next;
        }
        if(curr == nullptr) return false;
        prev->next = curr->next;
        delete curr;
        return true;
    }

    vector<int> getValues() {
        vector<int> vals;
        node * temp = head->next;
        while(temp) {
            vals.push_back(temp->val);
            temp = temp->next;
        }
        return vals;
    }
};
