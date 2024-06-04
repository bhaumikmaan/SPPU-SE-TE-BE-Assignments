package server;

import java.rmi.*;
import java.rmi.registry.*;

import remotes.Search;
import remotes.SearchQuery;

public class SearchServer {
   public static void main(String[] args) {
       try {
           Search search = new SearchQuery();
           Registry registry = LocateRegistry.createRegistry(1099);
           Naming.rebind("rmi://localhost:1099"+ "/REMOTE_SEARCH", search);
           System.out.println("Search Server ready");
       } catch (Exception e) {
           System.out.println("Search Server main " + e.getMessage());
       }
   }
}
