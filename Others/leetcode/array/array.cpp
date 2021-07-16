//1.Ways to output contents in an array
  for (int& item: a1) {
    cout << " " << item;
  }  
//2.Sort (ascend)
  sort(a1, a1 + sizeof(a1) / sizeof(*a1)); 
//3.Swap 
  swap(i, j);

//Vector (dynamic array in C++)
  //1.initialize
  vector<int> v0;
  vector<int> v1(5, 0);
  
  //2.make a copy
  vector<int> v2(v1.begin(), v1.end());
  vector<int> v3(v2);
  
  //3.cast an array to a vector
  int a[5] = {0, 1, 2, 3, 4};
  vector<int> v4(a, *(&a + 1));
  
  //4.get length
  v4.size();
  
  //5.access element
  v4[0];
  
  //6.sort
  sort(v4.begin(), v4.end());
  
  //7.add new element at the end of the vector
  v4.push_back(-1);
  
  //8.delete the last element
  v4.pop_back();
