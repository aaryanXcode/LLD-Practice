#include<bits/stdc++.h>

#include "Folder.h"
#include "File.h"
using namespace std;

int main(){
    Folder* root = new Folder("ROOT");
    File* rootFile = new File("root1.txt",2);
    File* rootFile2 = new File("root2.txt",2);
    

    Folder* image = new Folder("IMAGE");
    File* image1 = new File("image1.jpg",1);
    File* image2 = new File("image2.png",2);
    image->add(image1);
    image->add(image2);

    Folder* games = new Folder("GAMES");
    File* gta = new File("GTA 6",12);
    File* cod = new File("COD WARZONE",13);

    games->add(gta);
    games->add(cod);

    root->add(rootFile);
    root->add(rootFile2);
    root->add(image);
    root->add(games);
    root->openAll();
    cout<<"Total size of folder:"<<root->getSize()<<endl;

    FileSystem* pwd = root->cd("GAMES");
    cout<<pwd->getName()<<endl;
    cout<<pwd->getSize()<<endl;
    pwd->ls();
}