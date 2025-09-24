/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    
    if(par[x] != x){
        par[x] = find(par, par[x]);
    }
    return par[x];
}

void unionSet(int par[], int x, int z) {
    int lrep = find(par,x);
     int jrep = find(par,z);

     par[lrep]=jrep;
     
     return ;
}