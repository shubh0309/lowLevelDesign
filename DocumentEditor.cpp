#include<bits/stdc++.h>
using namespace std;

class DocumentElement{
    public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement{
    private:
        string text;
    public :
        TextElement(string text){
            this->text = text;
        }
        string render() override{
            return text;
        }
};

class ImageElement : public DocumentElement{
    private:
        string imagepath;
    public :
        ImageElement(string imagepath){
            this->imagepath = imagepath;
        }
        string render() override{
            return "image path : [" + imagepath + " ]";
        }
};

class Document{
    private:
        vector<DocumentElement*> documentElement;
    public:
        void addElement(DocumentElement* element){
            documentElement.push_back(element);
        }
        string render(){
            string result;
            for(auto ele : documentElement){
                result += ele->render();
            }
            return result;
        }
};

class Persistance{
    public:
    virtual void save(string data) = 0;
};

class SaveFile : public Persistance{
    public:
        void save(string data) override{
            ofstream outFile("document.txt");
            if(outFile){
                outFile <<data;
                outFile.close();
                cout<<"document saved in document.txt file\n";
            }
        }
};

class SaveDB : public Persistance{
    public: 
        void save(string data){
            cout<<" data saved to DB";
        }
};

class DocumentEditor{
    private:
        Document* document;
        Persistance* storage;
        string renderDocument;
    public:
        DocumentEditor(Document* document, Persistance* storage){
            this->document = document;
            this->storage = storage;
        }
        
        void addtext(string text){
            document->addElement(new TextElement(text));
        }
        
        void addImage(string imagePath){
            document->addElement(new ImageElement(imagePath));
        }
        
        string renderDoc(){
            if(renderDocument.empty()){
                renderDocument = document->render();
            }
            return renderDocument;
        }
        
        void saveDocument(){
            storage->save(renderDocument);
        }
};


int main(){
    Document* document = new Document();
    Persistance* persistance = new SaveFile();
    DocumentEditor* editor = new DocumentEditor(document, persistance);
    
    editor->addtext("Hello World \n");
    editor->addImage("picture.jpg");
    editor->addtext("Shubham \n");
    
    cout<<editor->renderDoc()<<endl;
    editor->saveDocument();
    return 0;
}
