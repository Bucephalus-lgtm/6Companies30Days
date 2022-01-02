string encode(string src)
{     
  //Your code here 
        string res = "";
        int count = 1;
        int i;
          
        for(i=0 ; i<src.length()-1 ; i++){
                if(src[i] == src[i+1]) count++;
                else if(src[i] != src[i+1]){
                    // cout << count << endl;
                    res = res + src[i] + to_string(count);
                    count = 1;
            }  
        }
          
        res = res + src[i] + to_string(count);
        return res;     
}  