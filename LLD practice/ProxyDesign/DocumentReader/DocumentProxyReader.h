#pragma once
#include "IDocument.h"
#include "TextDocumentReader.h"
#include "client.h"
#include<bits/stdc++.h>
using namespace std;
class DocumentProxyReader:public IDocument{
    string filename;
    Client* client;
    TextDocumentReader* textDocumentReader;
    public:
        DocumentProxyReader(string name,Client* client){
            this->filename = name;
            this->client = client;
            this->textDocumentReader = NULL;
        }

        void read() override {
            string inputPassword;
            cout << "Enter password: ";
            cin >> inputPassword;

            if (!client->isSubscribed()) {
                cout << "Please buy a subscription.\n";
                return;
            }

            if (!client->hasAccess(inputPassword)) {
                cout << "Incorrect password.\n";
                return;
            }

            if (textDocumentReader == nullptr) {
                textDocumentReader = new TextDocumentReader(filename);
            }

            textDocumentReader->read();
        }

        ~DocumentProxyReader() {
            delete textDocumentReader;
        }
};