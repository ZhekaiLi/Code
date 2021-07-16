//String
  //1.create 
  string s1 = "Hello World";
  string s2 = s1;
  string s3(s1);
  //2.compare
  s1 == "Hello World" == s2 == s3;
  s1.compare("Hello World") == s1.compare(s2) == s1.compare(s3) == 0;
  //3.find
  s1.find('o');
  //4.get substring
  s1.substr(startPositon, length);
  //5.tansform
  int i = stoi("1");
