package di.uniba.it.mri2223.lucene;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.document.TextField;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.IndexWriterConfig;
import org.apache.lucene.queryparser.classic.ParseException;
import org.apache.lucene.queryparser.classic.QueryParser;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.TopDocs;
import org.apache.lucene.store.FSDirectory;

public class AliceInWonderland {

	public static void main(String[] args) throws IOException {
		try {
			// Open a directory from the file system (index directory)
			FSDirectory fsdir = FSDirectory.open(new File("./resources").toPath());
			// IndexWriter configuration
			IndexWriterConfig iwc = new IndexWriterConfig(new StandardAnalyzer());
			// Index directory is created if not exists or overwritten
			iwc.setOpenMode(IndexWriterConfig.OpenMode.CREATE);
			// Create IndexWriter
			IndexWriter writer = new IndexWriter(fsdir, iwc);

			File file = new File("exercises\\MRI_2022-23_students\\resources\\Alice_Adv_Lewis_Carroll_utf8.txt");
			BufferedReader reader = new BufferedReader(new FileReader(file));
			String text = null;
			String testo = "";
			Document doc = null;
			String chapter = "";
			List<Document> documents = new ArrayList<>();

			while((text = reader.readLine()) != null) {
				if(text.contains("CHAPTER")){
					if(chapter != ""){
						doc.add(new TextField("text", testo, Field.Store.YES));
						documents.add(doc);
					}
					chapter = text;
					doc = new Document();
					doc.add(new TextField("name", "ALICE’S ADVENTURES IN WONDERLAND", Field.Store.YES));
					doc.add(new TextField("author", "Lewis Carroll", Field.Store.YES));
					doc.add(new TextField("title", chapter, Field.Store.YES));
					testo = "";
				} else if(chapter != ""){
					testo += text;
				}
			}

			reader.close();

			// Create document and add fields
			

			// add document to index
			writer.addDocuments(documents);
			// close IndexWriter
			writer.close();
			// Create the IndexSearcher
			IndexSearcher searcher = new IndexSearcher(DirectoryReader.open(fsdir));
			// Create the query parser with the default field and analyzer
			QueryParser qp = new QueryParser("name", new StandardAnalyzer());
			// Parse the query
			Query q = qp.parse("and");
			// Search
			TopDocs topdocs = searcher.search(q, 10);
			System.out.println("Found " + topdocs.totalHits.value + " document(s).");
		} catch (IOException | ParseException ex) {
			Logger.getLogger(HelloWorld.class.getName()).log(Level.SEVERE, null, ex);
		}
	}

}
