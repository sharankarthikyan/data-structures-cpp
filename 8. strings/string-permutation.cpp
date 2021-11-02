#include <iostream>
using namespace std;

void permutation(char source[], int k) {
    // Below two variables should be in static. The reason is `If we remove static then every recursive call makes a new fresh local variable`. In our case every call should handle the same globally located variable. So, we created static variable.
    static int aux[10] = {0};
    static char res[10];
    int i;

    if(source[k] == '\0') {
        res[k] = '\0';
        cout<<res<<endl;
    } else {
        for(i=0; source[i] != '\0'; i++) {
            if(aux[i] == 0) {
                res[k] = source[i];
                aux[i] = 1;
                permutation(source, k+1);
                aux[i] = 0;
            }
        }
    }   
}

int main() {
    char str[10];
    cin>>str;
    permutation(str, 0);
    return 0;
}