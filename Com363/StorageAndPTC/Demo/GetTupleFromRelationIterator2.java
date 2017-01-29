package Demo;

import PTCFramework.ProducerIterator;
import StorageManager.Storage;

public class GetTupleFromRelationIterator2 implements ProducerIterator<byte[]> {
    private final int BUFFER_BYTE_ARRAY_SIZE = 1024;
    private int currentPage = 0;
    private int nextpage = -1;
    private int dataEntryLength;
    private int dataEntriesRead = 0;
    private int maxDataEntries;
    private byte[] currentBuffer;
    private String fileName;
    private int pageSize;
    private Storage storage;

    public GetTupleFromRelationIterator2(String fName, int dataEntrySize, int pSize) throws Exception {
        storage = new Storage();
        fileName = fName;
        dataEntryLength = dataEntrySize;
        storage.LoadStorage(fName);
        pageSize = storage.pageSize;
        currentPage = pSize;
    }

    public boolean hasNext() {
        boolean next = false;
        if(nextpage != -1 || dataEntriesRead != maxDataEntries){
            next = true;
        }
        return next;
    }

    //Taken from print relation 1
    private int toInt(byte[] buffer, int offset) {
        int ret = 0;

        for(int i = 0; i < 4; i++) {
            ret <<= 8;
            ret |= buffer[offset + i] & 255;
        }

        return ret;
    }

    public byte[] next() {
        if(dataEntriesRead == maxDataEntries) {
            if(nextpage != 0) {
                currentBuffer = new byte[pageSize];

                try {
                    storage.ReadPage((long)nextpage, currentBuffer);
                    currentPage = nextpage;
                    nextpage = toInt(currentBuffer, 4);
                    maxDataEntries = toInt(currentBuffer, 0);
                    dataEntriesRead = 0;
                    byte[] byteArray = new byte[dataEntryLength];

                    for(int i = 0; i < dataEntryLength; i++) {
                        byteArray[i] = currentBuffer[8 + dataEntryLength * dataEntriesRead + i];
                    }

                    ++dataEntriesRead;
                    return (new String(byteArray)).getBytes();
                }
                catch (Exception e) {
                    return null;
                }
            }
        } else {
            byte[] byteArray = new byte[dataEntryLength];

            for(int i = 0; i < dataEntryLength; i++) {
                byteArray[i] = currentBuffer[8 + dataEntryLength * dataEntriesRead + i];
            }

            ++dataEntriesRead;
            return (new String(byteArray)).getBytes();
        }

        return null;
    }

    public void remove() {
    }

    public void open() throws Exception {
        currentBuffer = new byte[BUFFER_BYTE_ARRAY_SIZE];
        storage.ReadPage((long)currentPage, currentBuffer);
        nextpage = toInt(currentBuffer, 4);
        maxDataEntries = toInt(currentBuffer, 0);
        dataEntriesRead = 0;
    }

    public void close() throws Exception {
    }
}
