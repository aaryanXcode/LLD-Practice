#include<bits/stdc++.h>
#include "IDocument.h"
#include "TextDocumentReader.h"
#include "DocumentProxyReader.h"
#include "client.h"
using namespace std;

int main(){
    Client* client = new Client("Aryan", true, "pass123");
    IDocument* textDoc = new DocumentProxyReader("demo.txt",client);
    
    textDoc->read();
    delete textDoc;
    delete client;
    return 0;
}