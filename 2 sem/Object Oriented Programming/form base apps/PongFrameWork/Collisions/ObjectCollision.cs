using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PongFrameWork.Interfaces;
using PongFrameWork.Enums;

namespace PongFrameWork.Collisions
{
    public class ObjectCollision :CollisionsMethods
    {
        private ObjectType g1;
        private ObjectType g2;
        private ICollisionAction action;
        public ObjectCollision (ObjectType g1, ObjectType g2, ICollisionAction action)
        {
            this.g1 = g1;
            this.g2 = g2;
            this.action = action;
        }

        public ICollisionAction Action { get => action; set => action = value; }
        public ObjectType G1 { get => g1; set => g1 = value; }
        public ObjectType G2 { get => g2; set => g2 = value; }
    }
}
