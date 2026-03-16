// A Document is just data: title + pages.
// It exists independently of any printer.
// Because of that, the printer will only use it while printing
//  (association).

class Document {
    private String title;
    private int pages;

    // constructor - a method that creates an instance
    public Document(String dcument_title, int document_pages) {
        if (pages <= 0) {
            // SAFE DEFAULT
            pages = 1;
        }
        title = dcument_title;
        pages = document_pages;
    }

    // GETTERs to access the document
    public String getTitle() {
        return title;
    }
    public int getPages() {
        return pages;
    }
}