struct Message {
    string data<>;
    string user<>;
};

typedef Message Xat<>;

program PROGRAM_XAT {
    version VERSION_XAT {
        int writeMsg(Message) = 1;
        Xat getChat(int) = 2;
    } = 1;
} = 0x20000001; 