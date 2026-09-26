class Media:
    def __init__(self, id, title, language):
        self._id = id
        self._title = title
        self._language = language

class VideoFormat(Media):
    def __init__(self, id, title, language, resolution, aspect_ratio, extension):
        super().__init__(id, title, language)
        self._resolution = resolution
        self._aspect_ratio = aspect_ratio
        self._extension = extension

class Movie(VideoFormat):
    def __init__(self, id, title, language, resolution, aspect_ratio, extension, genre, director, duration):
        super().__init__(id, title, language, resolution, aspect_ratio, extension)
        self.__genre = genre
        self.__director = director
        self.__duration = duration 

    def get_row_data(self):
        return [self._id, self._title, self._language, self._resolution, self._aspect_ratio, self._extension, self.__genre, self.__director, self.__duration]

def show_table(movie_list):
    headers = ["ID", "Title", "Language", "Res", "Aspect", "Ext", "Genre", "Director", "Duration"]
    widths = [len(h) for h in headers]

    # Cari string terpanjang
    for movie in movie_list:
        row = movie.get_row_data()
        for i in range(9):
            if len(row[i]) > widths[i]:
                widths[i] = len(row[i])

    separator = "=" * (sum(widths) + 30) # 30 diambil dari total whitespace/gap
    
    # Cetak tabel dinamis
    print("\n" + separator)
    print(" | ".join([f"{headers[i]:<{widths[i]}}" for i in range(9)]))
    print(separator)
    for movie in movie_list:
        row = movie.get_row_data()
        print(" | ".join([f"{row[i]:<{widths[i]}}" for i in range(9)]))
    print(separator)

movie_list = [
    Movie("1", "2001: A Space Odyssey", "English", "4K", "2.20:1", ".mkv", "Sci-Fi", "Stanley Kubrick", "149"),
    Movie("2", "Se7en", "English", "4K", "2.39:1", ".mp4", "Mystery", "David Fincher", "127"),
    Movie("3", "Mulholland Drive", "English", "1080p", "1.85:1", ".mp4", "Thriller", "David Lynch", "147"),
    Movie("4", "Forrest Gump", "English", "4K", "2.35:1", ".mkv", "Drama", "Robert Zemeckis", "142"),
    Movie("5", "Backrooms", "English", "720p", "4:3", ".mp4", "Horror", "Kane Parsons", "9")
]

while True:
    choice = input("\n=== CINEMA ===\n1. Add Data\n2. Show Table\n3. Quit\nChoose: ")
    if choice == '1':
        id = input("ID: ")
        title = input("Title: ")
        lang = input("Language: ")
        res = input("Resolution: ")
        aspect = input("Aspect Ratio: ")
        ext = input("Extension: ")
        genre = input("Genre: ")
        dire = input("Director: ")
        dur = input("Duration (in minutes): ")
        
        movie_list.append(Movie(id, title, lang, res, aspect, ext, genre, dire, dur))
        print("Data berhasil ditambahkan!")
    elif choice == '2':
        show_table(movie_list)
    elif choice == '3':
        break