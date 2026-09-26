<?php
class Media {
    protected $id, $title, $language;
    public function __construct($id, $title, $language) {
        $this->id = $id; 
        $this->title = $title; 
        $this->language = $language;
    }
    public function getId() { return $this->id; }
    public function getTitle() { return $this->title; }
    public function getLanguage() { return $this->language; }
}

class VideoFormat extends Media {
    protected $resolution, $aspectRatio, $extension;
    public function __construct($id, $title, $language, $resolution, $aspectRatio, $extension) {
        parent::__construct($id, $title, $language);
        $this->resolution = $resolution; 
        $this->aspectRatio = $aspectRatio; 
        $this->extension = $extension;
    }
    public function getResolution() { return $this->resolution; }
    public function getAspectRatio() { return $this->aspectRatio; }
    public function getExtension() { return $this->extension; }
}

class Movie extends VideoFormat {
    private $genre, $director, $duration, $product_photo; 

    public function __construct($id, $title, $language, $resolution, $aspectRatio, $extension, $genre, $director, $duration, $product_photo = "") {
        parent::__construct($id, $title, $language, $resolution, $aspectRatio, $extension);
        $this->genre = $genre; 
        $this->director = $director; 
        $this->duration = $duration; 
        $this->product_photo = $product_photo;
    }
    public function getGenre() { return $this->genre; }
    public function getDirector() { return $this->director; }
    public function getDuration() { return $this->duration; }
    public function getFotoProduk() { return $this->product_photo; }
}

session_start();

if (!isset($_SESSION['movie_list'])) {
    $_SESSION['movie_list'] = [
        new Movie("1", "2001: A Space Odyssey", "English", "4K", "2.20:1", ".mkv", "Sci-Fi", "Stanley Kubrick", "149", "img/spaceodyssey.jpg"),
        new Movie("2", "Se7en", "English", "4K", "2.39:1", ".mp4", "Mystery", "David Fincher", "127", "img/se7en.jpg"),
        new Movie("3", "Mulholland Drive", "English", "1080p", "1.85:1", ".mp4", "Thriller", "David Lynch", "147", "img/mulhollanddrive.jpg"),
        new Movie("4", "Forrest Gump", "English", "4K", "2.35:1", ".mkv", "Drama", "Robert Zemeckis", "142", "img/forrestgump.jpg"),
        new Movie("5", "Backrooms", "English", "720p", "4:3", ".mp4", "Horror", "Kane Parsons", "102", "img/backrooms.jpg")
    ];
}

?>

<!DOCTYPE html>
<html>
<head><title>Movies List</title></head>
<body style="font-family: sans-serif; padding: 20px;">

    <h1>Movie List</h1>
    <table border="1" cellpadding="8" cellspacing="0" width="100%" style="white-space: nowrap; text-align: left;">
        <tr bgcolor="#f4f4f4">
            <th>Foto Produk</th>
            <th>ID</th>
            <th>Title</th>
            <th>Language</th>
            <th>Resolution</th>
            <th>Aspect</th>
            <th>Extension</th>
            <th>Genre</th>
            <th>Director</th>
            <th>Duration</th>
        </tr>
        <?php foreach ($_SESSION['movie_list'] as $m): ?>
        <tr>
            <td align="center"><?= $m->getFotoProduk() ? "<img src='{$m->getFotoProduk()}' width='50'>" : "None" ?></td>
            <td><?= $m->getId() ?></td>
            <td><?= $m->getTitle() ?></td>
            <td><?= $m->getLanguage() ?></td>
            <td><?= $m->getResolution() ?></td>
            <td><?= $m->getAspectRatio() ?></td>
            <td><?= $m->getExtension() ?></td>
            <td><?= $m->getGenre() ?></td>
            
            <td><?= $m->getDirector() ?></td>
            <td><?= $m->getDuration() ?></td>
        </tr>
        <?php endforeach; ?>
    </table>
</body>
</html>