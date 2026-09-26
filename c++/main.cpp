#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;


class Media {
protected:
    string id, title, language;
public:
    Media() {}
    Media(string id, string title, string language) {
        this->id = id; 
        this->title = title; 
        this->language = language;
    }
};


class VideoFormat : public Media {
protected:
    string resolution, aspectRatio, extension;
public:
    VideoFormat() {}
    VideoFormat(string id, string title, string language, string resolution, string aspectRatio, string extension) 
        : Media(id, title, language) {
        this->resolution = resolution; 
        this->aspectRatio = aspectRatio; 
        this->extension = extension;
    }
};


class Movie : public VideoFormat {
private:
    string genre, director, duration; 
public:
    Movie() {}
    Movie(string id, string title, string language, string resolution, string aspectRatio, string extension, string genre, string director, string duration) 
        : VideoFormat(id, title, language, resolution, aspectRatio, extension) {
        this->genre = genre; 
        this->director = director; 
        this->duration = duration;
    }
    
    
    vector<string> getRowData() {
        return {id, title, language, resolution, aspectRatio, extension, genre, director, duration};
    }
};

// tabel dinamis dengan menghitung string terpanjang di setiap baris
void showTable(Movie arr[], int total) {
    vector<string> headers = {"ID", "Title", "Language", "Res", "Aspect", "Ext", "Genre", "Director", "Duration"};
    vector<int> widths(9);
    
    
    for(int i = 0; i < 9; i++){
        widths[i] = headers[i].length();
    }
        

    
    for(int i = 0; i < total; i++) {
        vector<string> row = arr[i].getRowData();
        for(int j = 0; j < 9; j++) {
            if(row[j].length() > widths[j]) widths[j] = row[j].length();
        }
    }

    
    int totalWidth = 0;
    for(int i = 0; i < 9; i++){
        totalWidth += widths[i];
    }
    // total garis '=' dengan mengakumulasi total string terpanjang setiap baris ditambah dengan gap/whitespace
    totalWidth += 30; 
    string separator(totalWidth, '=');

    
    cout << "\n" << separator << "\n";
    for(int i = 0; i < 9; i++) {
        cout << left << setw(widths[i]) << headers[i];
        if(i < 8) cout << " | ";
    }
    cout << "\n" << separator << "\n";
    
    for(int i = 0; i < total; i++) {
        vector<string> row = arr[i].getRowData();
        for(int j = 0; j < 9; j++) {
            cout << left << setw(widths[j]) << row[j];
            if(j < 8) cout << " | ";
        }
        cout << "\n";
    }
    cout << separator << "\n";
}

int main() {
    Movie movieList[50];
    int total = 0;

    movieList[total++] = Movie("1", "2001: A Space Odyssey", "English", "4K", "2.20:1", ".mkv", "Sci-Fi", "Stanley Kubrick", "149");
    movieList[total++] = Movie("2", "Se7en", "English", "4K", "2.39:1", ".mp4", "Mystery", "David Fincher", "127");
    movieList[total++] = Movie("3", "Mulholland Drive", "English", "1080p", "1.85:1", ".mp4", "Thriller", "David Lynch", "147");
    movieList[total++] = Movie("4", "Forrest Gump", "English", "4K", "2.35:1", ".mkv", "Drama", "Robert Zemeckis", "142");
    movieList[total++] = Movie("5", "Backrooms", "English", "720p", "4:3", ".mp4", "Horror", "Kane Parsons", "101");

    while(true) {
        cout << "\n=== CINEMA ===\n1. Add Data\n2. Show Table\n3. Quit\nChoose: ";
        int choice; cin >> choice;

        if (choice == 1) {
            cin.ignore(); 
            string id, title, lang, res, aspect, ext, genre, dir, dur;
            cout << "ID: "; 
            getline(cin, id);

            cout << "Title: "; 
            getline(cin, title);

            cout << "Language: "; 
            getline(cin, lang);

            cout << "Resolution: "; getline(cin, res);
            cout << "Aspect Ratio: "; getline(cin, aspect);
            cout << "Extension: "; getline(cin, ext);
            cout << "Genre: "; getline(cin, genre);
            cout << "Director: "; getline(cin, dir);
            cout << "Duration (in minutes): "; getline(cin, dur);

            movieList[total++] = Movie(id, title, lang, res, aspect, ext, genre, dir, dur);
            cout << "Data berhasil ditambahkan!\n";
        } 
        else if (choice == 2) showTable(movieList, total);
        else if (choice == 3) break;
    }
    return 0;
}