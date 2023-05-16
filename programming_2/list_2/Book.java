package list_2;

class Book {
    
    String title;
    Integer pages;
    String publishing_company;
    Author author;
    
    Book()
    {
        title = "";
        pages = 0;
        publishing_company = "";
        author = new Author();
    }   

    Book(String title, Integer pages, String publishing_company) 
    {
        this.title = title;
        this.pages = pages;
        this.publishing_company = publishing_company;
    }
    
    
    
        
}
