typedef long long l;
int main(){
    l t;
    scanf("%lld",&t);
	while(t--){
		l n;
		scanf("%lld",&n);
		l a = 0;
		l h = 0;
		while(n--){
			double w;
			scanf("%lf",&w);
			if(w==0.5)h++;
			else a++;
		}
		printf("%lld\n",(1l<<a)*((1l<<h)-1));
	}
}