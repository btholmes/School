lexer grammar jsonContent;


fragment LOCAL: [0123456789a-zA-Z_~!$&'()*+,;=:-]+'.'?;
fragment DOMAIN: [0123456789a-zA-Z-]+'.'?;
fragment END: [0123456789a-zA-Z-]+;

EMAIL: '"EMAIL":'[ ]* '"' [ ]*LOCAL+'@'DOMAIN END[ ]* '"'[,]?
             {
                 int start = getText().indexOf('"', 7) + 1;
                 int end = getText().indexOf('"', start);
                 System.out.println("Found Email: " + getText().substring(start, end));
             };


WS: [ \r\n\t]+         {skip();} ;

BRACKET: [{|}] {skip();};

//WHITE: ' ' {skip(); };

EERROR: '"EMAIL":'[ ]* '"' .*? '"'[,]?
{
    System.out.println("Email error: " + getText());
};

fragment DAY: [0]*[123456789] | ([12][0123456789]) | '30' | '31';
fragment MONTH: [0]*[123456789] | ([1][012]);
fragment YEAR: ('20'[0123456789][0123456789])+ | '2100';

DATE: '"DATE":'[ ]* '"'[ ]* DAY[./-]*MONTH[./-]*YEAR [ ]*'"'[,]?
{
    int start = getText().indexOf('"', 7) + 1;
    int end = getText().indexOf('"', start);

    System.out.println("Found Date: " + getText().substring(start, end));
};

DERROR: '"DATE":'[ ]* '"' .*? '"'[,]?
{
    System.out.println("Date error: " + getText());
};

fragment THREEDIGIT: [ .-]?[0123456789][ .-]?[0123456789][ .-]?[0123456789][ .-]?;
fragment FOURDIGIT: [ .-]?[0123456789][ .-]?[0123456789][ .-]?[0123456789][ .-]?[0123456789][ .-]?;


PHONE: '"PHONE":'[ ]* '"'[ ]* '('?THREEDIGIT')'? THREEDIGIT FOURDIGIT [ ]*'"'[,]?
{
    int start = getText().indexOf('"', 8) + 1;
    int end = getText().indexOf('"', start);
    System.out.println("Found phone: " + getText().substring(start, end));
};

PERROR: '"PHONE":'[ ]* '"' .*? '"'[,]?
{
    System.out.println("Phone error: " + getText());
};

fragment TWODIGIT:  [ .-]*[0123456789][ .-]*[0123456789][ .-]*;

fragment VISA: ('4'THREEDIGIT FOURDIGIT FOURDIGIT FOURDIGIT | '4'THREEDIGIT FOURDIGIT FOURDIGIT [0123456789][ .-]?);
fragment MASTER: ('5'[ .-]?[12345]TWODIGIT FOURDIGIT FOURDIGIT FOURDIGIT);
fragment AMERICAN: ('3'[ .-]?[47]TWODIGIT FOURDIGIT FOURDIGIT THREEDIGIT);
fragment DINERS: ('30'[ .-]?[012345][.-]*[0123456789] FOURDIGIT FOURDIGIT TWODIGIT | '3'[68]TWODIGIT FOURDIGIT FOURDIGIT TWODIGIT);
fragment JOINTVENTURE: ('5'THREEDIGIT FOURDIGIT FOURDIGIT FOURDIGIT);
fragment DISCOVER: ('6011' FOURDIGIT FOURDIGIT FOURDIGIT | '65'TWODIGIT FOURDIGIT FOURDIGIT FOURDIGIT);
fragment JCB: ('2131' FOURDIGIT FOURDIGIT THREEDIGIT | '1800' FOURDIGIT FOURDIGIT THREEDIGIT | '35'TWODIGIT FOURDIGIT FOURDIGIT FOURDIGIT);

CREDIT: '"CREDITCARD":'[ ]* '"'[ ]* (VISA | MASTER | AMERICAN | DINERS | JOINTVENTURE | DISCOVER | JCB) [ ]*'"'[,]?
{
    int start = getText().indexOf('"', 13) + 1;
    int end = getText().indexOf('"', start);
    System.out.println("Found card: " + getText().substring(start, end));
};

CERROR: '"CREDITCARD":'[ ]* '"' .*? '"'[,]?
{
    System.out.println("Credit error: " + getText());
};

fragment FIVEDIGIT: [0123456789][0123456789][0123456789][0123456789][0123456789];

ADDRESS: '"Address":'[ ]* '"' [ ]*[0123456789]+ [ ]*[ a-zA-Z'_-]*[,]?  [ a-zA-Z]+[,][ ]*  [A-Z][A-Z][ ]* FIVEDIGIT [ ]*'"'[,]?
{
    int start = getText().indexOf('"', 9) + 1;
    int end = getText().indexOf('"', start);
    System.out.println("Found address: " + getText().substring(start, end));
};

AERROR: '"Address":'[ ]* '"' .*? '"'[,]?
{
    System.out.println("Address error: " + getText());
};

fragment OTHERELEMENTNAME: '"'[a-zA-Z0123456789._-]*'":'[ ]*;
fragment OTHERELEMENTRULES: '"'[ a-zA-Z0123456789_!$&'()*+,~;=:-]* '"';


OTHER: OTHERELEMENTNAME OTHERELEMENTRULES [,]?
{
    int start = getText().indexOf('"') + 1;
    int end = getText().indexOf('"', start);
    String name = getText().substring(start, end);

    int colon = getText().indexOf(':');
    int textStart = getText().indexOf('"', colon) + 1;
    int textEnd = getText().indexOf('"', textStart);
    String text = getText().substring(textStart, textEnd);

       if( name.length() >= 3){
         String xml = name.substring(0,3);
            if(Character.toLowerCase(xml.charAt(0)) == 'x' || Character.toLowerCase(xml.charAt(1)) == 'm' || Character.toLowerCase(xml.charAt(2)) == 'l'){
                System.out.println("Can't start an element with XML: " + getText());
            }else{
                       System.out.println("Found " +  name  + " : " + text);
            }
       }else{
             System.out.println("Found " +  name  + " : " + text);
       }


};

OERROR: '"' .*? '":'[ ]* '"' .*? '"'[,]?
{

    System.out.println("Error with : " + getText());
};

