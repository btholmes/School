package Demo;

import PTCFramework.ProducerIterator;
import StorageManager.Storage;

public class GetTupleFromRelationIterator2 implements ProducerIterator<byte[]> {
    int currentPage = 0;
    int nextpage = -1;
    int tuplelength;
    int tuplesRead = 0;
    int maxTuples;
    byte[] currentBuffer;
    String fileName;
    int pageSize;

    Storage storage;


    public GetTupleFromRelationIterator2(String fName, int tupleSize, int pSize) throws Exception {
        this.fileName = fName;
        this.tuplelength = tupleSize;
        this.storage = new Storage();
        this.storage.LoadStorage(fName);
        this.pageSize = this.storage.pageSize;
        this.currentPage = pSize;
    }

    public boolean hasNext() {

        boolean next = false;
        if(this.nextpage != -1 || this.tuplesRead != this.maxTuples){
            next = true;
        }
        return next;
    }

    private int toInt(byte[] var1, int var2) {
        int var3 = 0;

        for(int var4 = 0; var4 < 4; var4++) {
            var3 <<= 8;
            var3 |= var1[var2 + var4] & 255;
        }

        return var3;
    }

    public byte[] next() {
        byte[] byteArray;

        int i;
        if(this.tuplesRead == this.maxTuples) {
            if(this.nextpage == 0) {
                return null;
            } else {
                this.currentBuffer = new byte[this.pageSize];

                try {
                    this.storage.ReadPage((long)this.nextpage, this.currentBuffer);
                    this.currentPage = this.nextpage;
                    this.nextpage = this.toInt(this.currentBuffer, 4);
                    this.maxTuples = this.toInt(this.currentBuffer, 0);
                    this.tuplesRead = 0;
                    byteArray = new byte[this.tuplelength];

                    for(i = 0; i < this.tuplelength; i++) {
                        byteArray[i] = this.currentBuffer[8 + this.tuplelength * this.tuplesRead + i];
                    }

                    ++this.tuplesRead;
                    return (new String(byteArray)).getBytes();
                } catch (Exception var3) {
                    var3.printStackTrace();
                    return null;
                }
            }
        } else {
            byteArray = new byte[this.tuplelength];

            for(i = 0; i < this.tuplelength; i++) {
                byteArray[i] = this.currentBuffer[8 + this.tuplelength * this.tuplesRead + i];
            }

            ++this.tuplesRead;
            return (new String(byteArray)).getBytes();
        }
    }

    public void remove() {
    }

    public void open() throws Exception {
        this.currentBuffer = new byte[1024];
        this.storage.ReadPage((long)this.currentPage, this.currentBuffer);
        this.nextpage = this.toInt(this.currentBuffer, 4);
        this.maxTuples = this.toInt(this.currentBuffer, 0);
        this.tuplesRead = 0;
    }

    public void close() throws Exception {
    }
}
