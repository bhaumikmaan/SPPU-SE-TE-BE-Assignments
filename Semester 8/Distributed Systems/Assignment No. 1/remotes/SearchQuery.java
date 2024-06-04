package remotes;

import java.rmi.*;
import java.rmi.server.*;

public class SearchQuery extends UnicastRemoteObject implements Search {
   public SearchQuery() throws RemoteException {
       super();
   }

   public String query(String search) throws RemoteException {
       String result = "No results found";
       if (search.equals("p2p")) {
           result = "Found 1 result";
       }
       return result;
   }
}
