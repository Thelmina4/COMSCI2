// package labTask11;

import java.util.ArrayList;
import java.util.List;

interface Player {          // EQUALS public interface Player
    // it is interface so public is inferred

    // Registers the player with the GameLobby mediator.
    // Calls GameLobby.registerPlayer(this).
    // Outputs: [GameLobby] <PlayerType> <name> has joined the lobby.
    void joinGame();        // EQUALS public abstract void joinGame();

    // Removes the player from the GameLobby.
    // Calls GameLobby.removePlayer(this).
    // Outputs: [GameLobby] <PlayerType> <name> has left the lobby.
    void leaveGame();

    // Sends a message through the GameLobby mediator.
    // Calls GameLobby.sendMessage(message, this).
    // Outputs:  [<name>] sends: "<message>"
    // [GameLobby] Message from <name>: "<message>"
    void sendMessage(String message);

    // Outputs: [<name>] received: "<message>"
    void receiveMessage(String message);

    // Returns one of: "HumanPlayer", "AIPlayer", "Spectator".
    String getPlayerType();

    String getName();
}

abstract class AbstractPlayer implements Player {
    protected String name;
    protected GameLobby lobby;

    public AbstractPlayer(String name, GameLobby lobby) {
        setName(name);
        this.lobby = lobby;
    }
    @Override
    public String getName() {
        return this.name;
    }
    public void setName(String name) {
        if (name != null && !name.trim().isEmpty()) this.name = name;
    }

    @Override
    public void sendMessage(String message) {
        // [<name>] sends: "<message>"
        System.out.println("[" + name + "] sends: \"" + message + "\"");
        lobby.sendMessage(message, this);
    }
    @Override
    public void receiveMessage(String message) {
        System.out.println("[" + name + "] received: \"" + message + "\"");
    }
    public abstract String getPlayerType();
}

class AdminPlayer extends AbstractPlayer {
    public AdminPlayer(String name, GameLobby lobby) {
        super(name, lobby);
    }
    @Override
    public String getPlayerType() {
        return "AdminPlayer";
    }
    @Override
    public void joinGame() {
        lobby.registerPlayer(this);
    }
    @Override
    public void leaveGame() {
        lobby.removePlayer(this);
    }
    public void kickPlayer(String name) {
        lobby.kickPlayer(name, this);
    }
}

class HumanPlayer extends AbstractPlayer {
    public HumanPlayer(String name, GameLobby lobby) {
        super(name, lobby);
    }
    // Registers the player with the GameLobby mediator.
    // Calls GameLobby.registerPlayer(this).
    // Outputs: [GameLobby] <PlayerType> <name> has joined the lobby.
    @Override
    public String getPlayerType() {
        return "HumanPlayer";
    }
    @Override
    public void joinGame() {
        // REGISTER PLAYER
        lobby.registerPlayer(this);
        // System.out.println("[GameLobby] " + getPlayerType() + " " + name + " has joined the lobby.");
    }
    @Override
    public void leaveGame() {
        // Removes the player from the GameLobby.
        // Calls GameLobby.removePlayer(this).
        // Outputs: [GameLobby] <PlayerType> <name> has left the lobby.        }
        lobby.removePlayer(this);
        // System.out.println("[GameLobby] " + getPlayerType() + " " + name + " has left the lobby.");    
    }
}

class AIPlayer extends AbstractPlayer {
    public AIPlayer(String name, GameLobby lobby) {
        super(name, lobby);
    }
    @Override
    public String getPlayerType() {
        return "AIPlayer";
    }
    @Override
    public void joinGame() {
        // REGISTER PLAYER
        lobby.registerPlayer(this);
        // System.out.println("[GameLobby] " + getPlayerType() + " " + name + " has joined the lobby.");
    }
    @Override
    public void leaveGame() {
        // Removes the player from the GameLobby.
        // Calls GameLobby.removePlayer(this).
        // Outputs: [GameLobby] <PlayerType> <name> has left the lobby.        }
        lobby.removePlayer(this);
        // System.out.println("[GameLobby] " + getPlayerType() + " " + name + " has left the lobby.");    
    }   
}

class Spectator extends AbstractPlayer {
    // constructor
    public Spectator(String name, GameLobby lobby) {
        super(name, lobby);
    }
    @Override
    public String getPlayerType() {
        return "Spectator";
    }
    @Override
    public void joinGame() {
        // REGISTER PLAYER
        lobby.registerPlayer(this);
        // System.out.println("[GameLobby] " + getPlayerType() + " " + name + " has joined the lobby.");
    }
    @Override
    public void leaveGame() {
        // Removes the player from the GameLobby.
        // Calls GameLobby.removePlayer(this).
        // Outputs: [GameLobby] <PlayerType> <name> has left the lobby.        }
        lobby.removePlayer(this);
        // System.out.println("[GameLobby] " + getPlayerType() + " " + name + " has left the lobby.");    
    }

    // override the send message
    @Override
    public void sendMessage(String message) {
        // [<name>] sends: "<message>"
        System.out.println("[GameLobby] Spectators cannot send messages.");
    }
}
class GameLobby {
    //  class GameLobby that manages players and game communication. Stores a list of Player objects.
    // should I have called this lobby? instead of players
    private List<Player> players = new ArrayList<>();

    void registerPlayer(Player player) {
        players.add(player);
        System.out.println("[GameLobby] " + player.getPlayerType() + " " + ((AbstractPlayer)player).getName() + " has joined the lobby.");
    }
    void removePlayer(Player player) {
        players.remove(player);
        // (You need the cast because name is not in the Player interface.)
        //  ((AbstractPlayer)player).getName()
        System.out.println("[GameLobby] " + player.getPlayerType() + " " + ((AbstractPlayer)player).getName() + " has left the lobby.");
    }
    void sendMessage(String message, Player sender) {

        // String senderName = (AbstractPlayer(sender).getName());
        // System.out.println("[" +  ((AbstractPlayer)sender).getName() + "] sends: \"" + message + "\"");
        System.out.println("[GameLobby] Message from " +  ((AbstractPlayer)sender).getName() + ": \"" + message + "\"");
        
        for (Player p: players) {
            if (p != sender ) {
                p.receiveMessage(message);
            }
        }
    }

    int viablePlayers() {
        int count = 0;
        for (Player p : players) {
            if (!p.getPlayerType().equals("Spectator") && !(p instanceof AdminPlayer)) {
                count++;
            }
        }
        // System.out.println("count = " + count);
        return count;
    }
    void startMatch() {
        if (viablePlayers() < 2) {
            System.out.println("[GameLobby] Not enough players to start a match.");
            return;
        } 
        // System.out.print("[GameLobby] Starting game with players: ");
        // make a loop to find not spectator
        List<String> names = new ArrayList<>();
        for (Player p: players) {
            if (!(p instanceof Spectator) && !(p instanceof AdminPlayer)) {
                names.add(((AbstractPlayer)p).getName());
            }
        }    
        //  make a \n at the end
        System.out.println("[GameLobby] Starting game with players: " + String.join(", ", names));
    }

    void kickPlayer(String name, AdminPlayer admin) {
        // I have Player array already. 
        // check if name in player.getname
        // if there && player != admin:  then remove
        // else not found
        for (Player p: players) {
            // System.out.println(p.getName() + " " + p.getName().equals(name));

            if (p.getName().equals(name) && !(p instanceof AdminPlayer)) {
                // [GameLobby] Admin <AdminName> kick ed <PlayerType> <name> from the lobby.
                System.out.println("[GameLobby] Admin " +
                    admin.getName() + " kicked " +
                    p.getPlayerType() + " " + name +
                    " from the lobby.");
                // players.remove(p);

                removePlayer(p);
                return;
            }            
        }
        System.out.println("[GameLobby] Player " + name + " not found.");
    }

    // public static void main(String[] args) {
    //     GameLobby2 lobby = new GameLobby2();
    //     Player alice = new HumanPlayer("Alice", lobby);
    //     Player bot = new AIPlayer("Botx", lobby);
    //     Player bob = new Spectator("bob", lobby);
    //     Player thelma = new AdminPlayer("thelma", lobby);

    //     alice.joinGame();
    //     bot.joinGame();
    //     bob.joinGame();
    //     thelma.joinGame();

    //     alice.sendMessage("LOL");
    //     bob.sendMessage("Shut up, Alice");  // Spectator tries to send a message
    //     lobby.startMatch();
    //     // bob.leaveGame();
    //     // bot.leaveGame();
    //     // alice.leaveGame();

    //     thelma.sendMessage("Welcome to the lobby!");
    //     ((AdminPlayer) thelma).kickPlayer("bob");
    //     lobby.startMatch();
    // } 
}

