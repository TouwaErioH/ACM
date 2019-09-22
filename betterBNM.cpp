// 三次乘法。由于还没有实现大整数减法（或支持负数的加法），暂时还是伪代码 见https://zhuanlan.zhihu.com/p/83468752
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string multi(string A, string B); //计算大整数相乘
string Plus(string q, string w, string e, string r); //计算大整数相加
stringstream ss;

int main() {
      string A, B;
      while (cin >> A >> B) {
      cout << multi(A, B) << endl;
      }
      return 0;
}

string multi(string A, string B) {
      int len_A = A.length();
      int len_B = B.length();
      if (len_A == 1) {
      if (len_B == 1) { //最基本的情况：A和B都是一位数，把A、B从string转为int（我这里用的stringstream），然后相乘后转回为string型return回去。
      ss << A;
      int a;
      ss >> a;
      ss.clear();
      ss << B;
      int b;
      ss >> b;
      ss.clear();
      ss << b*a;
      string str_out;
      ss >> str_out;
      ss.clear();
      return str_out;
      }
      else {//A是个位数，B不是的情况下，按照分治的思想把B分开分别与A相乘。
      string B1, B2;
      B1 = B.substr(0, len_B / 2);
      B2 = B.substr(len_B / 2);
      string AB1 = multi(A, B1);
      string AB2 = multi(A, B2);
      cout<<AB1<<endl<<AB2<<endl;
      if (AB2.length() > B2.length()) {   //此时AB2最多比B2多出一位
      string str = AB2.substr(0, 1);
        /*ss << AB1;     漏洞,此时AB1可能已经超出int范围了
        int ab1;
        ss >> ab1;*/
        string tp0(AB1.length()-1,'0');
        str=tp0+str;
        string u0(AB1.length(),'0');
        AB1=Plus(AB1,str,u0,u0);
        return AB1 + AB2.substr(1);
      }
      else
        return AB1 + AB2;
        }
    }
      else {
      if (len_B == 1) {//B是个位数，A不是的情况与上述A是个位数B不是的情况相同。
      string A1, A2;
      A1 = A.substr(0, len_A / 2);
      A2 = A.substr(len_A / 2);
      string A1B = multi(A1, B);
      string A2B = multi(A2, B);
      if (A2B.length() > A2.length()) {
        string str = A2B.substr(0, 1);
        string tp0(A1B.length()-1,'0');
        str=tp0+str;
        string u0(A1B.length(),'0');
        A1B=Plus(A1B,str,u0,u0);
        return A1B + A2B.substr(1);
        }
      else {
        return A1B + A2B;
        }
        }
      else {//A和B都不是个位数，就按照上述方法分治就可以了，只是为了最后相加的时候方便，把返回的四个部分都用0凑成了位数相同的。
      string A1, A2, B1, B2;
      A1 = A.substr(0, len_A / 2);
      A2 = A.substr(len_A / 2);
      B1 = B.substr(0, len_B / 2);
      B2 = B.substr(len_B / 2);
      string part1_ = multi(A1, B1);
	  part1_ = multi(2, part1_);
      string part1_0(A2.length()+B2.length(), '0');   //长度为A2.length()+B2.length()的0串
      part1_ = part1_ + part1_0;                      //2*A1B1*10(n2,m2)
      string part2_ = multi(A2, B2);
	  part2_ =multi(2,part2_);
      string part2_00(part1_.length() - part2_.length(), '0');
      part2_ = part2_00 + part2_;                     //2*A2B2，高位补0
	  
	  
      string part3_ = A1;
      string part3_0(A2.length(), '0');             //(A1*10(n2)-A2)
      part3_ = part3_ + part3_0;                    //A1*10(n2)  伪代码
	  part3_= part_3-A2                             //大整数减法（或支持负数的大整数加法），未实现
      
	  
	  
      string part4_ = B1;                           //(B2-B1*10(m2))
      string part4_0=(B2.length(), '0'); 
      part4_ = part4_ + part4_0;
	  part4_= B2-part4_;                           //伪代码
	  
	  part5_= multi(part4_,part3_)                
	  
      string part5_00(part1_.length() - part5_.length(), '0');
      part5_ = part5_00 + part5_;
	  string u0(part1_.length(), '0');
      return Plus(part1_, part2_, part5_, u0);   
    }
    }
}

string Plus(string q, string w, string e, string r) { //大整数相加，qwer位数相同
      int len_q = q.length();
      string y, out;
      int a, b, c, d;
      for (int i = 1; i <= len_q; i++) {  //逐位相加
    ss << q.substr(len_q - i, 1);
    ss >> a;
    ss.clear();
    ss << w.substr(len_q - i, 1);
    ss >> b;
    ss.clear();
    ss << e.substr(len_q - i, 1);
    ss >> c;
    ss.clear();
    ss << r.substr(len_q - i, 1);
    ss >> d;
    ss.clear();
    ss << a + b + c + d;
    ss >> y;
    ss.clear();
      if (i == 1)
      out = y;
      else if (out.length() > i - 1) {  //进一位
      ss << out.substr(0, 1);
      ss >> a;
      ss.clear();
      ss << y;
      ss >> b;
      ss.clear();
      ss << a + b;
      ss >> y;
      ss.clear();
      out = y + out.substr(1);
    }
      else {
      out = y + out;
    }
    }
	return out;
}
