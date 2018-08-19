void Heap::Insert(int x){
    if(size + 1 == cap) // do not over grow heap
        return;
    a[size++] = x; // add at the end of heap
    percolate_up(size-1); // for heap-order property
}

void Heap::percolate_up(int pos){
    int parent = (pos - 1)/2; // parent index
    while (pos > 0 && a[pos] > a[parent]){
        swap(a[pos],a[parent]); // fix heap-order property
        pos = parent;
        parent = (pos -1)/2;
    }

}

void Heap::deleteMax(){
    if(!size)// Check empty heap
        return;
    swap(a[0],a[--size]); // swap & shrink
    percolate_dn(0); // for heap-order property
}

void Heap::percolate_dn(int pos){
    int child = 2*pos + 1; // left child index
    while (c < size){
        if (c+1 < size && a[c+1] > a[c])
            c++; //locate the larger child
        if(a[pos] >= a[c]) // heap-order property holds
            break;
        pos = c;
        c = 2*pos + 1;
    }
}

void heapsort(int a[], int n){
    //Heapify
    for(int i = (n-2)/2; i >= 0; i--)
        percolate_dn(i);
    // Remove max & turn semiheap -> heap
    for(int i = n-1; i >= 0; i--){
        swap(a[0], a[i]);
        percolate_dn(0);
    }
}
