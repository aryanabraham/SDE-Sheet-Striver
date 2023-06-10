string reverseString(string &str){
	// Write your code here.
	int i = str.length();
    int j = i;
    
    str.push_back(' ');

    while(j > -1){
        while((j > -1) && (str[j] == ' '))
            j--;
        
        if(j < 0)
			break;

        int k = (j - 1);

        while((k > -1) && (str[k] != ' ')) 
            k--;
        
        str.append(str.substr((k + 1), (j - k)));
		str.push_back(' ');

        j = (k - 1);
    }
    return str.substr((i + 1), (str.length() - (i + 2)));

}
