lexer grammar xmlContent;


fragment LOCAL: [0123456789a-zA-Z_~!$&'()*+,;=:-]+'.'?;
fragment DOMAIN: [0123456789a-zA-Z-]+'.'?;
fragment END: [0123456789a-zA-Z-]+;

EMAIL: '<email>'[ ]*LOCAL+'@'DOMAIN END [ ]*'</email>'
             {
                 System.out.println("Found Email: " + getText().substring(7,getText().length()-8));
             };


WS: [ \r\n\t]+         {skip();} ;

EERROR: '<email>' .*? '</email>'
{
    System.out.println("Email error: " + getText());
};

fragment DAY: [0]*[123456789] | ([12][0123456789]) | '30' | '31';
fragment MONTH: [0]*[123456789] | ([1][012]);
fragment YEAR: ('20'[0123456789][0123456789])+ | '2100';

DATE: '<date>'[ ]*DAY[./-]*MONTH[./-]*YEAR [ ]*'</date>'
{
    System.out.println("Found Date: " + getText().substring(6,getText().length()-7));
};

DERROR: '<date>' .*? '</date>'
{
    System.out.println("Date error: " + getText());
};

fragment THREEDIGIT: [ .-]?[0123456789][ .-]?[0123456789][ .-]?[0123456789][ .-]?;
fragment FOURDIGIT: [ .-]?[0123456789][ .-]?[0123456789][ .-]?[0123456789][ .-]?[0123456789][ .-]?;


PHONE: '<phone>'[ ]*'('?THREEDIGIT')'? THREEDIGIT FOURDIGIT[ ]*'</phone>'
{
    System.out.println("Found phone: " + getText().substring(7,getText().length()-8));
};

PERROR: '<phone>' .*? '</phone>'
{
    System.out.println("Phone error: " + getText());
};

fragment TWODIGIT:  [ .-]?[0123456789][ .-]?[0123456789][ .-]?;

fragment VISA: ('4'THREEDIGIT FOURDIGIT FOURDIGIT FOURDIGIT | '4'THREEDIGIT FOURDIGIT FOURDIGIT [0123456789][ .-]?);
fragment MASTER: ('5'[ .-]?[12345]TWODIGIT FOURDIGIT FOURDIGIT FOURDIGIT);
fragment AMERICAN: ('3'[ .-]?[47]TWODIGIT FOURDIGIT FOURDIGIT THREEDIGIT);
fragment DINERS: ('30'[ .-]?[012345][.-]*[0123456789] FOURDIGIT FOURDIGIT TWODIGIT | '3'[68]TWODIGIT FOURDIGIT FOURDIGIT TWODIGIT);
fragment JOINTVENTURE: ('5'THREEDIGIT FOURDIGIT FOURDIGIT FOURDIGIT);
fragment DISCOVER: ('6011' FOURDIGIT FOURDIGIT FOURDIGIT | '65'TWODIGIT FOURDIGIT FOURDIGIT FOURDIGIT);
fragment JCB: ('2131' FOURDIGIT FOURDIGIT THREEDIGIT | '1800' FOURDIGIT FOURDIGIT THREEDIGIT | '35'TWODIGIT FOURDIGIT FOURDIGIT FOURDIGIT);

CREDIT: '<creditcard>'[ ]*(VISA | MASTER | AMERICAN | DINERS | JOINTVENTURE | DISCOVER | JCB)[ ]*'</creditcard>'
{
    System.out.println("Found card: " + getText().substring(12,getText().length()-13));
};

CERROR: '<creditcard>' .*? '</creditcard>'
{
    System.out.println("Credit error: " + getText());
};


fragment FIVEDIGIT: [0123456789][0123456789][0123456789][0123456789][0123456789];

ADDRESS: '<Address>' [ ]*[0123456789]+ [ ]*[ a-zA-Z'_-]*[,]?  [ a-zA-Z]+[,][ ]*  [A-Z][A-Z][ ]* FIVEDIGIT [ ]*'</Address>'
{
    int start = getText().indexOf('>', 1) + 1;
    int end = getText().indexOf('<', start);
    System.out.println("Found address: " + getText().substring(start, end));
};

AERROR: '<Address>'  .*? '</Address>'
{
    System.out.println("Address error: " + getText());
};


fragment OTHERELEMENTNAME: '<'[a-zA-Z0123456789._-]*'>';
fragment ENDOTHERNAME: '</'[a-zA-Z0123456789._-]*'>' ;
fragment OTHERELEMENTRULES: [ a-zA-Z0123456789_!$&'()*+,~;=:-]*;




OTHER: OTHERELEMENTNAME OTHERELEMENTRULES ENDOTHERNAME
{
    int start = getText().indexOf('>') + 1;
    int end = getText().indexOf('<', start);
    String opening = getText().substring(1, start-1);
    String ending = getText().substring(end+2, getText().length()-1);


    if( opening.length() >= 3){
     String xml = opening.substring(0,3);
        if(Character.toLowerCase(xml.charAt(0)) == 'x' || Character.toLowerCase(xml.charAt(1)) == 'm' || Character.toLowerCase(xml.charAt(2)) == 'l'){
            System.out.println("Can't start an element with XML: " + getText());
        }else if(opening.equals(ending)){
                  System.out.println("Found " + getText().substring(1, start-1) + " : " + getText().substring(start, end));
        }else{
                 System.out.println("Tags don't match: " + getText());
        }
    }else if(opening.equals(ending)){
         System.out.println("Found " + getText().substring(1, start-1) + " : " + getText().substring(start, end));
    }else{
        System.out.println("Tags don't match: " + getText());
    }


};

OERROR: ('<' .*? '>' .*? '</' .*? '>' | '<'.*? '>' .*? '</' .*? '>')
{
    System.out.println("Element error: " + getText());
};
