ll n=1;
const ll MAXN= 1000000;
ll bonus[MAXN];
void bubble_up(int i ){
    if (bonus[i/2]<bonus[i] && i!=1){
        swap(bonus[i],bonus[i/2]);
        bubble_up(i/2);
    }
    else{return;}
}

void bubble_down(int i){
    if (2*i < n && bonus[i] < bonus[2*i] && (2*i+1 >= n or bonus[2*i+1] < bonus[2*i])){
        swap(bonus[2*i],bonus[i]);
        bubble_down(2*i);
    }
     else if (2*i+1 < n && bonus[2*i+1] > bonus[i]){
        swap(bonus[2*i+1],bonus[i]);
        bubble_down(2*i+1);
    }    
}