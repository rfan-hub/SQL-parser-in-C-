bool SqlEx::ForDelete(){
    vector<vector<string>> Vdelete;

    regex a1("(?<=delete from )\.+(?=where )");
    regex a2("(?<=where )\.+(?=END)");

    string dstr[2];
    smatch dsm[2];

    string::const_iterator st = Ex.begin();
    string::const_iterator en = Ex.end();

    if(regex_search(Ex,dsm[0],a1)){
        vector<string>vdelete1;
        dstr[0]=dsm[0].str();
        vdelete1.push_back(dstr[0]);
        cout<<"delete from:"<<endl;
        cout<<dstr[0]<<endl;
        cout<<endl;
        Vdelete.push_back(vdelete1);
    }else{
        cout<<"检查delete from与where之间是否存在错误"<<endl;
    }
    if(regex_search(Ex,dsm[1],a2)){
        vector<string>vdelete1;
        cout<<"where:"<<endl;

        dstr[1]=dsm[1].str();
        regex rr("(\.+?and )|(\.+?or )");
        smatch rrsm;
        string::const_iterator st=dstr[1].begin();
        string::const_iterator en=dstr[1].end();
        bool flag=false;
        while(regex_search(st,en,rrsm,rr)){
            flag =true;
            cout<<rrsm.str()<<endl;
            vdelete1.push_back(rrsm.str());
            st=rrsm[0].second;
        }
        if(flag){
                regex_search(st,en,rrsm,regex("\.+"));
                cout<<rrsm.str()<<endl;
                vdelete1.push_back(rrsm.str());
        }
        else{
                cout<<dstr[1]<<endl;
            vdelete1.push_back(dstr[1]);
        }
        Vdelete.push_back(vdelete1);
    }else{
        cout<<"检查where语句后是否存在错误！！"<<endl;
    }
    result=Vdelete;
    return true;
}

bool SqlEx::ForInsert(){
    vector<vector<string>> Vinsert;

    regex a1("(?<=insert into )\.+(?=values)");
    regex a2("(?<=values\\()\.+(?=\\)END)");

    string istr[2];
    smatch ism[2];

    if(regex_search(Ex,ism[0],a1)){
        vector<string>vinsert1;
        istr[0]=ism[0].str();

        regex rr("(?<=\\()\.+(?=\\))");
        smatch rsm;
         cout<<"Insert into:"<<endl;
        if(regex_search(istr[0],rsm,rr)){
            regex rr2("\.+?(?=\\()");
            smatch rsm2;
            regex_search(istr[0],rsm2,rr2);
            cout<<rsm2.str()<<endl;
            cout<<endl;
            vinsert1.push_back(rsm2.str());

            string rstr=rsm.str();

            smatch rsm1;
            regex rr1("(?<=')\.+?(?=')") ;
            string::const_iterator st=rstr.begin();
            string::const_iterator en=rstr.end();

            while(regex_search(st,en,rsm1,rr1)){
                if(rsm1.str()!=","){
                    cout<<rsm1.str()<<endl;
                    vinsert1.push_back(rsm1.str());
                }
                st=rsm1[0].second;
            }
        }else{
                vinsert1.push_back(istr[0]);
                cout<<istr[0]<<endl;
        }
        Vinsert.push_back(vinsert1);
        cout<<endl;
    }else{
        cout<<"检查insert into语句后是否存在错误！！！"<<endl;
        return false;
    }
    if(regex_search(Ex,ism[1],a2)){
            vector<string>vinsert2;
        istr[1]=ism[1].str();
        cout<<"Values:"<<endl;
        smatch rsm3;
        regex rr3("(?<=')\.+?(?=')") ;
        string::const_iterator st=istr[1].begin();
        string::const_iterator en=istr[1].end();

        while(regex_search(st,en,rsm3,rr3)){
            if(rsm3.str()!=","){
                cout<<rsm3.str()<<endl;
                vinsert2.push_back(rsm3.str());
            }
            st=rsm3[0].second;
        }
        Vinsert.push_back(vinsert2);
    }else{
        cout<<"检查values语句后是否存在错误！！！"<<endl;
        return false;
    }
    result=Vinsert;
    return true;
}