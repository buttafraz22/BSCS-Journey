using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing;
using System.Threading.Tasks;
using PongFrameWork.Interfaces;
using PongFrameWork.Movements;
using PongFrameWork.Collisions;
using PongFrameWork.Enums;

namespace PongFrameWork
{
    public class Game:IEventRaise
    {
        int gravity;
     
        private List<GameObject> gameObjectList;
        private List<ObjectCollision> collisions;
        private List<Fire> firing;

        public EventHandler onGameObjectAdded;
        public EventHandler onHittingPlayer;
        public EventHandler whenFirre;
        public EventHandler OnFire;

        public EventHandler onHittingPill;
        private ProgressBarP proBar;

        public ProgressBarP ProBar { get => proBar; set => proBar = value; }

        /*
         public ProgressBar proBar = new ProgressBar();
         */

        public Game(int gravity)
        {
            this.gravity = gravity;
            gameObjectList = new List<GameObject>();
            collisions = new List<ObjectCollision>();
            proBar = new ProgressBarP();
            firing= new List<Fire>();
        }
        public void RaiseCollisionEvent(GameObject Go)
        {
            if(Go.OType ==Enums.ObjectType.pill)
            {
                onHittingPill?.Invoke(Go.Pb1 , EventArgs.Empty);
            }
            else
            {
                onHittingPlayer?.Invoke(Go, EventArgs.Empty);
            }
        }
        public Game()
        {
            collisions = new List<ObjectCollision>();
            gameObjectList = new List<GameObject>();
            proBar = new ProgressBarP();
            firing = new List<Fire>();
        }
        public void update()
        {
            foreach (GameObject go in gameObjectList)
            {
               go.MoveGameObj();
            }
            if(firing != null)
            {
                foreach(Fire f in firing)
                {
                    f.Pb1.Location = f.Movement.Move(f.Pb1.Location);
                }
            }
        }
        public Point getPlayerPos()
        {
            foreach(GameObject go in gameObjectList)
            {
                if(go.OType == ObjectType.player)
                {
                    return go.Pb1.Location;
                }
            }
            return new Point(0,0);
        }
        public void keyPressed(Keys keyCode)
        {
            foreach(GameObject go in gameObjectList)
            {
                if(go.Movement.GetType() == typeof(keyMovements))
                {
                    keyMovements key = (keyMovements)go.Movement;
                    key.keyPress(keyCode);
                   // break;
                }
            }
        }
        public void moveFire(Keys Key, Image img , Point location ,  IMovement movement)
        {
            if (Key == Keys.Space)
            {
                addFire(img, location, movement);
                if (firing != null)
                {
                    foreach (Fire f in firing)
                    {
                        f.Pb1.Location = f.Movement.Move(f.Pb1.Location);
                    }
                }
            }
        }
        public void addFire(Image img , Point location , IMovement movement)
        {
            Fire f = new Fire(img, location, movement,ObjectType.fires);
            whenFirre?.Invoke(f.Pb1, EventArgs.Empty);
            firing.Add(f);
        }
        public void AddGameObject(Image img,int left,int top , IMovement movement,ObjectType o)
        {
            GameObject g = new GameObject(img, left, top,movement,o);
            gameObjectList.Add(g);
            onGameObjectAdded?.Invoke(g.Pb1, EventArgs.Empty);
        }
        public void addCollisons(ObjectCollision c)
        {
            this.collisions.Add(c);
        }
        public void detectCollision()
        {
            for(int i = 0; i < gameObjectList.Count; ++i)
            {
                for(int j = 0; j < gameObjectList.Count; ++j)
                {
                    //checking for collisions in the game
                    if (gameObjectList[i].Pb1.Bounds.IntersectsWith(gameObjectList[j].Pb1.Bounds))
                    {
                        foreach(ObjectCollision c in collisions)
                        {
                            if(gameObjectList[i].OType == c.G1 && gameObjectList[j].OType == c.G2)
                            {
                                c.Action.performAction(this, gameObjectList[i], gameObjectList[j]);
                                ProBar.decrementProgressBar(10);
                            }
                        }
                    }
                }
            }
        }
        public void detectCollision(ref int score)
        {
            for (int i = 0; i < gameObjectList.Count; ++i)
            {
                for (int j = 0; j < gameObjectList.Count; ++j)
                {
                    //checking for collisions in the game
                    if (gameObjectList[i].Pb1.Bounds.IntersectsWith(gameObjectList[j].Pb1.Bounds))
                    {
                        score += 10;                  
                    }
                }
            }
        }

        public void detectFireCollision()
        {
            for (int i = 0; i < firing.Count; ++i)
            {
                for (int j = 0; j < gameObjectList.Count; ++j)
                {
                    //checking for collisions in the game
                    if (firing[i].Pb1.Bounds.IntersectsWith(gameObjectList[j].Pb1.Bounds))
                    {
                        foreach (ObjectCollision c in collisions)
                        {
                            if (firing[i].OType == c.G1 && gameObjectList[j].OType == c.G2)
                            {
                                CollisionsMethods.performAction1(this, firing[i], gameObjectList[j]);
                            }
                        }
                    }
                }
            }
        }
        public void removeFire(Fire f)
        {
            OnFire?.Invoke(f.Pb1, EventArgs.Empty);
        }
    }
}
