grammar Polish;
@header {
   import java.util.Stack;
}
@members {
Stack<String> vals=new Stack<String>();
Boolean error=false;
}

VAL : ('0''1''2''3''4''5''6''7''8''9')|(('true')|('false'));
OPP : '*'|'/'|'+'|'-'|'%'|'&&'|'||'|'!'|'<'|'<='|'>'|'>='|'=='|'!=';
END : ';';

WS : [ \r\t\n]+ -> skip ;


start
   :  ((expr)* END {
         if(vals.empty())
         {
            System.out.print("INVALID EXPRESSION;");
         }
         else
         {
            String temp=vals.pop();
            if(vals.empty())
            {
               System.out.print(temp+";");
            }
            else
            {
               System.out.print("INVALID EXPRESSION;");
            }
         }
         vals=new Stack<String>();
         error=false;
      } )+
   ;

expr
   :  (VAL {
         if(!error)
         {
            vals.push($VAL.text);
         }
      })+
      (OPP {
         if(!error)
         {
            if(vals.empty())
            {
               System.out.print("Opp '"+$OPP.text+"' does not have enough values ");
               error=true;
            }
            else
            {
               String val1=vals.pop();
               String s=$OPP.text;
               
               if(s.equals("+"))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '+' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
                     {
                        System.out.print(" Cannot add boolean variables.");
                        error=true;
                     }
                     else
                     {
                        int i1=Integer.parseInt(val1);
                        int i2=Integer.parseInt(val2);
                        vals.push(Integer.toString(i2+i1));
                     }
                  }
               }
               else if(s.equals("-"))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '-' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
                     {
                        System.out.println("Cannot subtract boolean variables. ");
                        error=true;
                     }
                     else
                     {
                        int i1=Integer.parseInt(val1);
                        int i2=Integer.parseInt(val2);
                        vals.push(Integer.toString(i2-i1));
                     }
                  }
               }
               else if(s.equals("*"))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '*' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
                     {
                        System.out.println("Cannot multiply boolean variables. ");
                        error=true;
                     }
                     else
                     {
                        int i1=Integer.parseInt(val1);
                        int i2=Integer.parseInt(val2);
                        vals.push(Integer.toString(i2*i1));
                     }
                  }
               }
               else if(s.equals("/"))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '\' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
                     {
                        System.out.print("Cannot divide boolean variables. ");
                        error=true;
                     }
                     else
                     {
                        int i1=Integer.parseInt(val1);
                        int i2=Integer.parseInt(val2);
                        vals.push(Integer.toString(i2/i1));
                     }
                  }
               }
               else if(s.equals("%"))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '%' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
                     {
                        System.out.print("Cannot mod boolean variables. ");
                        error=true;
                     }
                     else
                     {
                        int i1=Integer.parseInt(val1);
                        int i2=Integer.parseInt(val2);
                        vals.push(Integer.toString(i2%i1));
                     }
                  }
               }
               else if(s.equals("<"))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '<' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
                     {
                        System.out.print("Cannot compare boolean variables. ");
                        error=true;
                     }
                     else
                     {
                        int i1=Integer.parseInt(val1);
                        int i2=Integer.parseInt(val2);
                        Boolean b=(i2<i1);
                        vals.push(String.valueOf(b));
                     }
                  }
               }
               else if(s.equals("<="))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '<=' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
                     {
                        System.out.print("Cannot compare boolean variables. ");
                        error=true;
                     }
                     else
                     {
                        int i1=Integer.parseInt(val1);
                        int i2=Integer.parseInt(val2);
                        Boolean b=(i2<=i1);
                        vals.push(String.valueOf(b));
                     }
                  }
               }
               else if(s.equals(">"))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '>' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
                     {
                        System.out.print("Cannot compare boolean variables. ");
                        error=true;
                     }
                     else
                     {
                        int i1=Integer.parseInt(val1);
                        int i2=Integer.parseInt(val2);
                        Boolean b=(i2>i1);
                        vals.push(String.valueOf(b));
                     }
                  }
               }
               else if(s.equals(">="))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '>=' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
                     {
                        System.out.print("Cannot compare boolean variables. ");
                        error=true;
                     }
                     else
                     {
                        int i1=Integer.parseInt(val1);
                        int i2=Integer.parseInt(val2);
                        Boolean b=(i2>=i1);
                        vals.push(String.valueOf(b));
                     }
                  }
               }
               else if(s.equals("=="))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '==' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     Boolean b=(val2.equals(val1));
                     vals.push(String.valueOf(b));
                  }
               }
               else if(s.equals("!="))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '!=' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     Boolean b=(!(val2.equals(val1)));
                     vals.push(String.valueOf(b));
                  }
               }
               else if(s.equals("!"))
               {
                  if(val1.equals("true"))
                  {
                     vals.push("false");
                  }
                  else if(val1.equals("false"))
                  {
                     vals.push("true");
                  }
                  else
                  {
                     System.out.print("Cannot 'not' non-booleans ");
                     error=true;
                  }
               }
               else if(s.equals("&&"))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '&&' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     if((val1.equals("true") || val1.equals("false")) && (val2.equals("true") || val2.equals("false")))
                     {
                        Boolean b=val2.equals(val1);
                        vals.push(String.valueOf(b));
                     }
                     else
                     {
                        System.out.print("Cannot compare non-boolean variables ");
                        error=true;
                     }
                  }
               }
               else if(s.equals("||"))
               {
                  if(vals.empty())
                  {
                     System.out.print("Opp '||' does not have enough values ");
                     error=true;
                  }
                  else
                  {
                     String val2=vals.pop();
                     if((val1.equals("true") || val1.equals("false")) && (val2.equals("true") || val2.equals("false")))
                     {
                        Boolean b1=Boolean.parseBoolean(val1);
                        Boolean b2=Boolean.parseBoolean(val2);
                        Boolean b=(b1||b2);
                        vals.push(String.valueOf(b));
                     }
                     else
                     {
                        System.out.print("Cannot compare non-boolean variables ");
                        error=true;
                     }
                  }
               }
               
               
            }
         }
      })*
      
   ;