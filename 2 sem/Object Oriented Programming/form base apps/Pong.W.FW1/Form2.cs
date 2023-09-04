using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using PongFrameWork.Enums;
using PongFrameWork;
using PongFrameWork.Collisions;
using PongFrameWork.Movements;

namespace Pong.W.FW1
{
    public partial class Form2 : Form
    {
        Game game;
        Point bounds;
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
           // label1.Text = "100";
            Random rnd = new Random();
            game = new Game(15);

            this.Height = 700;
            this.Width = 700;

            game.onGameObjectAdded += new EventHandler(Game_onGameObjectAdded);
            game.onHittingPlayer += new EventHandler(OnHittingPlayer);
            game.onHittingPill += new EventHandler(OnHittingPill);
            game.OnFire += new EventHandler(pressFire);

            /*
             * game.ProBar.decrementprogressBar += new EventHandler(ProgressBar_OnDecrementScore);
             * game.ProBar.decrementProgressBar(10);
             */

            bounds = new Point(this.Width, this.Height);

            // defining movements
            keyMovements keys = new keyMovements(10, bounds);
            ComputerVertical comp = new ComputerVertical(10, bounds, "up");
            noMovement nM = new noMovement();
            Diagonal dg = new Diagonal(10, bounds, this.Height, 0, 100, "downRight");
            int pillPos = rnd.Next(15, 200);

            //adding game objects
            game.AddGameObject(Pong.W.FW1.Properties.Resources.arrow, this.Width - 100, this.Height - 100,comp, ObjectType.player);
            game.AddGameObject(Pong.W.FW1.Properties.Resources.arrow, 0, 0, keys, ObjectType.player);

            game.AddGameObject(Properties.Resources.pill, pillPos, pillPos, nM, ObjectType.pill);
            game.AddGameObject(Properties.Resources.barrel, pillPos, pillPos, dg, ObjectType.ball);

            // adding collisions

            ObjectCollision c = new ObjectCollision(ObjectType.player, ObjectType.ball, new CollisionsMethods());
            ObjectCollision b = new ObjectCollision(ObjectType.pill, ObjectType.ball, new CollisionsMethods());

            game.addCollisons(b);
            game.addCollisons(c);

        }
        private void Game_onGameObjectAdded(Object sender, EventArgs e)
        {
            PictureBox Pb = (PictureBox)sender;
            this.Controls.Add(Pb);
        }
        private void OnHittingPlayer(Object sender, EventArgs e)
        {
            GameObject go = (GameObject)sender;
            go.Pb1.Location = go.Movement.Move(go.Pb1.Location);
        }
        private void OnHittingPill(Object sender, EventArgs e)
        {
            PictureBox Pb = (PictureBox)sender;
            this.Controls.Remove(Pb);
        }
        private void pressFire(object sender, EventArgs e)
        {
            PictureBox p = (PictureBox)sender;
            this.Controls.Remove(p);
        }
        
        private void timer1_Tick(object sender, EventArgs e)
        {
            game.update();
            game.detectCollision();
        }

        private void Form2_KeyDown(object sender, KeyEventArgs e)
        {
            game.keyPressed(e.KeyCode);
        }
    }
}
