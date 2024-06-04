package client;

import java.rmi.*;

import remotes.Search;

public class ClientRequest {
   public static void main(String[] args) {
       try {
           String search = (args.length < 1) ? "p2p" : args[0];
           String url = "rmi://localhost:1099/REMOTE_SEARCH";
           Search access = (Search) Naming.lookup(url);
           String result = access.query(search);
           System.out.println("Found: " + result);
       } catch (Exception e) {
           System.out.println("ClientRequest exception: " + e.getMessage());
       }
   }
}
