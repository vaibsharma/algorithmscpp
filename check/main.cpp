#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

typedef long long int lli;
using namespace std;

bool funct(pair<pair<lli,lli>,pair<lli,lli> > a,pair<pair<lli,lli>,pair<lli,lli> > b) {
	return a.first.second < b.first.second;
}

int main()
{
    vector<pair< pair<lli,lli>,pair<lli,lli> > > hor,longi;
    lli checkHor( vector<pair< pair<lli,lli>,pair<lli,lli> > >,lli);
    lli checkVer( vector<pair< pair<lli,lli>,pair<lli,lli> > >,lli);
    lli n=0,k=0,s=0,mn=0,mx=0,hx=0,hy=0,tx=0,ty=0;
    int T=0;
    pair<lli,lli> head,tail;
    pair< pair<lli,lli>,pair<lli,lli> > snake;
    scanf("%d",&T);
    while(T--){
    	hor.clear();
    	longi.clear();

        scanf("%lld %lld %lld",&n,&k,&s);
        for(lli x=0;x<s;x++){
            scanf("%lld %lld %lld %lld",&hx,&hy,&tx,&ty);
            if(hx == tx){

                if( !( ((hy < ((n-k)/2 +1)) && (ty<((n-k)/2 +1)) ) || ( (hy>((n+k)/2) ) && (ty>((n+k)/2) )  ) ) ){
                    mn = min(hy,ty);
                    mx = max(hy,ty);
                    mn = (mn<((n-k)/2 +1))? ((n-k)/2 +1):mn;
                    mx = (mx>((n+k)/2))? ((n+k)/2):mx;
                    head= make_pair(hx,mn);
                    tail=make_pair(hx,mx);
                    snake=make_pair(head,tail);
                    hor.push_back(snake);
                }
                else{
                	longi.push_back(make_pair(make_pair(hx,hy),make_pair(hx,hy)));
                }
            }
            else{

                if( !( ((hx < ((n-k)/2 +1)) && (tx<((n-k)/2 +1)) ) || ( (hx>((n+k)/2) ) && (tx>((n+k)/2) )  ) ) ){
                    mn = min(hx,tx);
                    mx = max(hx,tx);
                    mn = (mn<((n-k)/2+1))? ((n-k)/2+1):mn;
                    mx = (mx>((n+k)/2))? ((n+k)/2):mx;
                    head= make_pair(mn,hy);
                    tail=make_pair(mx,hy);
                    snake=make_pair(head,tail);
                    longi.push_back(snake);
                }
                else{
                	hor.push_back(make_pair(make_pair(hx,hy),make_pair(hx,hy)));
                }

            }
        }
        sort(hor.begin(),hor.end(),funct);
        sort(longi.begin(),longi.end());


        for(lli c=0;c<hor.size();c++){
            cout<<hor[c].first.first<<","<<hor[c].first.second<<"|"<<hor[c].second.first<<","<<hor[c].second.second<<" ";
        }
        // for(lli c=0;c<longi.size();c++){
        //     cout<<longi[c].first.first<<","<<longi[c].first.second<<"|"<<longi[c].second.first<<","<<longi[c].second.second<<" ";
        // }
        cout<<checkHor(hor,k);
        // cout<<"\n"<<checkVer(longi,k);
        if(T){
        	printf("\n");
        }
    }

    return 0;
}

lli checkHor(vector<pair<pair<lli,lli>,pair<lli,lli> > > v,lli k){
	//check second value;
	lli count=1,sum=0,end=v[0].second.second,x=1,leng=v[0].second.second-v[0].first.second,pos=0,start=v[0].first.second;
	lli allias = start,length=end-start+1;
	cout<<"The kength of array "<<v.size()<<"\n";
	while(x < v.size()){
		sum=0;
		if(length>=k){
			break;
		}
		while(allias<=end && x<v.size()){
			if(sum<(v[x].second.second - end)){
				sum = v[x].second.second - end;
				pos=x;
					// cout<<"selected "<<v[x].first.first<<","<<v[x].first.second<<" "<<v[x].second.first<<","<<v[x].second.second<<"\n";
			}

			allias = v[x].first.second;
			x++;
		}
		x=pos;
		if(sum>0){
			cout<<"The sum we got is"<<sum<<"\n";
			cout<<"selected "<<v[x].first.first<<","<<v[x].first.second<<" "<<v[x].second.first<<","<<v[x].second.second<<"\n";
			cout<<x<<"\n";
			end = v[x].second.second;
			allias = v[x].first.second;
			length+=sum;
			count++;

		}
//  		x*=2;
// 	x=3;
	}
	if(length<k){
		cout<<"The total sum we coiuld find was "<<length<<"\n";
		return -1;
	}
	else{
	    cout<<"The total sum we coiuld find was "<<length<<"\n";
		return count;
	}
}



// lli checkHor(vector< pair<pair<lli,lli>,pair<lli,lli>> > v,lli k){
// 	lli end= v[0].second.first,start=v[0].first.first,x=1,count=0;
// 	lli len = end-start+1,pos=0,su=0;
// 	lli allias = start;
// 	while(pos<v.size() && x<v.size()){
// 		su=0;
// 		while(allias<=end && x<v.size()){
// 			if(v[x].second.first-end > su){
// 				su = v[x].second.first-end;
// 				allias = v[x].first.first;
// 				pos = x;
// 			}
// 			x++;
// 		}
// 		if(su!=0){
// 			count++;
// 		}
// 		len+=su;
// 		if(len>=k) break;
// 		end = v[pos].second.first;
// 	}
// 	if(len<k){
// 		return -1;
// 	}
// 	else return count;
// }

// lli checkVer(vector< pair<pair<lli,lli>,pair<lli,lli>> > v,lli k){
// 	lli end= v[0].second.second,start=v[0].first.second,x=1,count=0;
// 	lli len = end-start+1,pos=0,su=0;
// 	lli allias = start;
// 	while(pos<v.size() && x<v.size()){
// 		su=0;
// 		while(x<v.size()){
// 			if(v[x].second.second-end > su){
// 				su = v[x].second.second-end;
// 				allias = v[x].first.first;
// 				pos = x;
// 			}
// 			x++;
// 		}
// 		if(su!=0){
// 			count++;
// 			cout<<v[pos].first.first<<","<<v[pos].first.second<<"|"<<v[pos].second.first<<","<<v[pos].second.second<<" ";
// 		}
// 		len+=su;
// 		if(len>=k) break;
// 		end = v[pos].second.second;
// 		x=pos;
// 	}
// 	if(len<k){
// 		return -1;
// 	}
// 	else return count;
// }

