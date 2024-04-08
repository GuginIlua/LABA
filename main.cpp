#include <iostream>
#include <fstream>

#include "person.h"
#include "functions.h"

using namespace std;
using namespace functions;

int main() {
    int n{};
    int a;
    int b;
    int c;
    int key=0;
    cout << "Create array for n=";
    cin >> n;
    Person * arr = new Person[n];
    if (n < 1)
        return 0;
    for (int i = 0; i < n; i++) {
        string name;
        int age;
        int sallary;
        cout << "name[" << i << "]=";
        cin >> name;
        cout << "age[" << i << "]=";
        cin >> age;
        cout << "sallary[" << i << "]=";
        cin >> sallary;
        arr[i].setName(name);
        arr[i].setAge(age);
        arr[i].setSallary(sallary);
    }

    cout << "\ncreated arr:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "name[" << i << "]=" << arr[i].name() << endl;
        cout << "age[" << i << "]=" << arr[i].age() << endl;
        cout << "sallary[" << i << "]=" << arr[i].sallary() << endl;
    }

    save(arr, n);
    while(1){
    cout<<"\n1-write,2-read,3-end"<<endl;
    cin>>a;
    if(a<0||a>3) return 0;
    if(a==3)
        break;
    if(a==1){
        cout<<"1-create full new one,2-change this array,3-add new elements,4-delete element"<<endl;
        cin>>b;
        if(b<0||b>4) return 0;
        if(b==1){
            cout << "Create array for n=";
            cin >> n;
            Person * arr = new Person[n];
            if (n < 1)
                return 0;
            for (int i = 0; i < n; i++) {
                string name;
                int age;
                int sallary;
                cout << "name[" << i << "]=";
                cin >> name;
                cout << "age[" << i << "]=";
                cin >> age;
                cout << "sallary[" << i << "]=";
                cin >> sallary;
                arr[i].setName(name);
                arr[i].setAge(age);
                arr[i].setSallary(sallary);
                save(arr, n);
            }
        }
        if(b==2){
            cout<<"Which one?"<<endl;
            cin>>c;
            arr=load(n);
            for(int i=0;i<=c;i++){
                if(i==c){
                    string name;
                    int age;
                    int sallary;
                    cout << "name[" << i << "]=";
                    cin >> name;
                    cout << "age[" << i << "]=";
                    cin >> age;
                    cout << "sallary[" << i << "]=";
                    cin >> sallary;
                    arr[i].setName(name);
                    arr[i].setAge(age);
                    arr[i].setSallary(sallary);
                    save(arr, n);
                }

            }
        }
        if(b==3){
           string name;
           int age;
           int sallary;
           Person * arr2 = new Person[n+1];
           for (int i = 0; i < n; i++){
           arr2[i]=arr[i];
           }
           delete[] arr;
           Person * arr = new Person[n+1];
           for (int i = 0; i < n+1; i++){
           arr[i]=arr2[i];
           }
           delete[] arr2;
           cout << "name[" << n << "]=";
           cin >> name;
           cout << "age[" << n << "]=";
           cin >> age;
           cout << "sallary[" << n << "]=";
           cin >> sallary;
           arr[n].setName(name);
           arr[n].setAge(age);
           arr[n].setSallary(sallary);
           save(arr, n+1);
        }
        if(b==4){
            cout<<"Which one?"<<endl;
            cin>>c;
            for(int i=0;i<n;i++){
                if(i==c){
                    Person * arr2 = new Person[n-1];
                    for (int i = 0; i < c; i++){
                    arr2[i]=arr[i];
                    }
                    for (int i = c+1; i < n-1; i++){
                    arr2[i]=arr[i];;
                    }
                    delete[] arr;
                    Person * arr = new Person[n-1];
                    for (int i = 0; i < n-1; i++){
                    arr[i]=arr2[i];
                    }
                    delete[] arr2;
                    save(arr, n-1);
                }
            }
        }

   }
    if(a==2){
        cout<<"1-Load full array,2-find element"<<endl;
        cin>>c;
        if(c<0||c>2) return 0;
        if(c==1){
    cout << "\nloading from txt file:" << endl;

    arr = load(n);
    cout << "loaded n=" << n << endl;
    if (!arr) {
        cout << "arr is null" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << "name[" << i << "]=" << arr[i].name() << endl;
        cout << "age[" << i << "]=" << arr[i].age() << endl;
        cout << "sallary[" << i << "]=" << arr[i].sallary() << endl;
    }
        }
        if(c==2){
            cout<<"1-name,2-age,3-sallary"<<endl;
            cin>>c;
            if(c<0||c>3) return 0;
            if(c==1){
                string name1;
                cout<<"name="<<endl;
                cin>>name1;
                for(int i=0;i<n;i++){
                    if(arr[i].name()==name1){
                        cout<<"\nfound:"<<endl;
                        cout << "name[" << i << "]=" << arr[i].name() << endl;
                        cout << "age[" << i << "]=" << arr[i].age() << endl;
                        cout << "sallary[" << i << "]=" << arr[i].sallary() << endl;
                        key=1;
                    }
                }
                if(key==0) cout<<"\nnot found"<<endl;
                 key=0;
            }
            if(c==2){
                int age2;
                cout<<"age="<<endl;
                cin>>age2;
                for(int i=0;i<n;i++){
                    if(arr[i].age()==age2){
                        cout<<"\nfound:"<<endl;
                        cout << "name[" << i << "]=" << arr[i].name() << endl;
                        cout << "age[" << i << "]=" << arr[i].age() << endl;
                        cout << "sallary[" << i << "]=" << arr[i].sallary() << endl;
                        key=1;
                    }
                }
                if(key==0) cout<<"\nnot found"<<endl;
                 key=0;
            }
            if(c==3){
                int sal2;
                cout<<"sallary="<<endl;
                cin>>sal2;
                for(int i=0;i<n;i++){
                    if(arr[i].sallary()==sal2){
                        cout<<"\nfound:"<<endl;
                        cout << "name[" << i << "]=" << arr[i].name() << endl;
                        cout << "age[" << i << "]=" << arr[i].age() << endl;
                        cout << "sallary[" << i << "]=" << arr[i].sallary() << endl;
                        key=1;
                    }
                }
                if(key==0) cout<<"\nnot found"<<endl;
                key=0;
            }
        }
    }
    }
    delete [] arr;



    return 0;
}


