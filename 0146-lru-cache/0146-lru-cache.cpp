class LRUCache
{
    public:
        class node{
            public:
            int key;
            int val;
            node*next;
            node*prev;
            node(int _key, int _value)
            {
                key= _key;
                val= _value;
            }
        };
    
    node* head = new node(-1,-1);//Initialized. 
    node* tail = new node(-1,-1);
    int max_cap;
    unordered_map<int,node*>m;//int , Address is stored. 
    
    LRUCache(int capacity)//Initial config. 
    {
        max_cap=capacity;
        head->next=tail;
        tail->prev =head;
    }
    
    void addnode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    void deletenode(node* delnode)
    {
        node*delprev = delnode->prev;
        node*delnext= delnode->next;
        delprev->next= delnext;
        delnext->prev = delprev;
    }
    int get(int key_)
    {
       if (m.find(key_) != m.end())//I.e it exists in the map. 
       {
           node*resnode = m[key_];//Address. 
           int res = resnode->val;
           m.erase(key_);
           deletenode(resnode);
           addnode(resnode);//Right after head. 
           m[key_] = head->next;//New addr. updated. 
           return res;
       }
        return -1;// Because it did not find it. 
    }
    void put(int key_,int value)
    {
        if(m.find(key_)!=m.end())
        {
            node*existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if(m.size() == max_cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_,value));
        m[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */