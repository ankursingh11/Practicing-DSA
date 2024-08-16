
// https://www.geeksforgeeks.org/problems/operations-on-binary-min-heap/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=operations-on-binary-min-heap

int MinHeap::extractMin() 
{
    // if size 0 return -1;
    if(heap_size <= 0)
    {
        return -1;
    }
    
    
    // if size is 1 then don't call MinHeapify() function
    if(heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
    
    // top element la store kara
    int root = harr[0];
    
    // last element la, top la aana
    harr[0] = harr[heap_size-1];
    
    // last cha element la pop kara
    heap_size--;
    
    // top cha element la correct place kara 
    MinHeapify(0);
    
    return root;
    
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    if(i>= heap_size) return;
    decreaseKey(i,INT_MIN);
    extractMin();
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k) 
{
    if(heap_size  == capacity) return;
    
    heap_size++;
    harr[heap_size -1] =k;
    
    int index = heap_size-1;
    
    while(index >0)
    {
        int p = parent(index);
        if(harr[p] > harr[index])
        {
            swap(harr[p],harr[index]);
            index = p;
        }
        else{
            return;
        }
    }
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val) 
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) 
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}