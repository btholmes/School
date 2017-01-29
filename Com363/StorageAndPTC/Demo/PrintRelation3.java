package Demo;

public class PrintRelation3{
    public static void main(String args[]) throws Exception{
        System.out.println("The tuples after loading file to Relation are: ");
        GetTupleFromRelationIterator2 getTupleFromRelationIterator= new GetTupleFromRelationIterator2("myDisk1", 35, 0);
        getTupleFromRelationIterator.open();
        while(getTupleFromRelationIterator.hasNext()){
            byte [] tuple = getTupleFromRelationIterator.next();

            if(toInt(tuple, 31) >= 50000){
                System.out.println(new String(toInt(tuple, 0)+", "+new String(tuple).substring(4, 27)+", "+ toInt(tuple, 31)));
            }else {
                System.out.println(new String(toInt(tuple, 0)+", "+new String(tuple).substring(4, 27)+", "+ new String(tuple).substring(27,31)+", "+ toInt(tuple, 31)));

            }
        }
    }


    private static int toInt(byte[] bytes, int offset) {
        int ret = 0;
        for (int i=0; i<4; i++) {
            ret <<= 8;
            ret |= (int)bytes[offset+i] & 0xFF;
        }
        return ret;
    }
}