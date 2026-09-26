import java.util.Scanner;


class Media {
    protected String id, title, language;
    public Media(String id, String title, String language) {
        this.id = id; 
        this.title = title; 
        this.language = language;
    }
}


class VideoFormat extends Media {
    protected String resolution, aspectRatio, extension;
    public VideoFormat(String id, String title, String language, String resolution, String aspectRatio, String extension) {
        super(id, title, language);
        this.resolution = resolution; 
        this.aspectRatio = aspectRatio; 
        this.extension = extension;
    }
}

class Movie extends VideoFormat {
    private String genre, director, duration; 

    public Movie(String id, String title, String language, String resolution, String aspectRatio, String extension, String genre, String director, String duration) {
        super(id, title, language, resolution, aspectRatio, extension);
        this.genre = genre; 
        this.director = director; 
        this.duration = duration;
    }
    
    
    public String[] getRowData() {
        return new String[]{id, title, language, resolution, aspectRatio, extension, genre, director, duration};
    }
}

public class App {
    public static void showTable(Movie[] arr, int total) {
        String[] headers = {"ID", "Title", "Language", "Res", "Aspect", "Ext", "Genre", "Director", "Duration"};
        int[] widths = new int[9];
        
        
        for (int i = 0; i < 9; i++){
            widths[i] = headers[i].length();
        } 

        for (int i = 0; i < total; i++) {
            String[] row = arr[i].getRowData();
            for (int j = 0; j < 9; j++) {
                if (row[j].length() > widths[j]) widths[j] = row[j].length();
            }
        }

        int totalWidth = 0;
        for (int i = 0; i < 9; i++) {
            totalWidth += widths[i];
        }
        totalWidth += 30;
        String separator = "=".repeat(totalWidth);

        System.out.println("\n" + separator);
        for (int i = 0; i < 9; i++) {
            System.out.printf("%-" + widths[i] + "s", headers[i]);
            if (i < 8) System.out.print(" | ");
        }
        System.out.println("\n" + separator);
        
        for (int i = 0; i < total; i++) {
            String[] row = arr[i].getRowData();
            for (int j = 0; j < 9; j++) {
                System.out.printf("%-" + widths[j] + "s", row[j]);
                if (j < 8) System.out.print(" | ");
            }
            System.out.println();
        }
        System.out.println(separator);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Movie[] movieList = new Movie[50];
        int total = 0;

        movieList[total++] = new Movie("1", "2001: A Space Odyssey", "English", "4K", "2.20:1", ".mkv", "Sci-Fi", "Stanley Kubrick", "149");
        movieList[total++] = new Movie("2", "Se7en", "English", "4K", "2.39:1", ".mp4", "Mystery", "David Fincher", "127");
        movieList[total++] = new Movie("3", "Mulholland Drive", "English", "1080p", "1.85:1", ".mp4", "Thriller", "David Lynch", "147");
        movieList[total++] = new Movie("4", "Forrest Gump", "English", "4K", "2.35:1", ".mkv", "Drama", "Robert Zemeckis", "142");
        movieList[total++] = new Movie("5", "Backrooms", "English", "720p", "4:3", ".mp4", "Horror", "Kane Parsons", "101");

        while (true) {
            System.out.println("\n=== CINEMA ===\n1. Add Data\n2. Show Table\n3. Quit\nChoose: ");
            System.out.print("Pilih: ");
            int choice = input.nextInt(); input.nextLine(); 

            if (choice == 1) {
                System.out.print("ID: "); 
                String id = input.nextLine();

                System.out.print("Title: "); 
                String title = input.nextLine();

                System.out.print("Language: "); 
                String lang = input.nextLine();

                System.out.print("Resolution: "); 
                String res = input.nextLine();

                System.out.print("Aspect Ratio: "); 
                String aspect = input.nextLine();

                System.out.print("Extension: "); 
                String ext = input.nextLine();

                System.out.print("Genre: "); 
                String genre = input.nextLine();

                System.out.print("Director: "); 
                String dir = input.nextLine();

                System.out.print("Duration (in minutes): "); 
                String dur = input.nextLine();

                movieList[total++] = new Movie(id, title, lang, res, aspect, ext, genre, dir, dur);
                System.out.println("Data berhasil ditambahkan!");
            } 
            else if (choice == 2) showTable(movieList, total);
            else if (choice == 3) break;
        }
        input.close();
    }
}