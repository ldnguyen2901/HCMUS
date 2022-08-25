using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MainData;

namespace HotelManagement
{
    class Program
    {
        static void UpdateNumberofRooms(Hotel hotel)
        {
            hotel.ValNumberofRoom = hotel.Rooms.Count;
        }
        static void Main(string[] args)
        {
            Hotel hotel = new Hotel();
            hotel.ValName = "Ngoi Sao";
            hotel.HotelAddorRemoveEvent += new Hotel.HotelHandler(UpdateNumberofRooms);

            hotel.AddRoom(new Room("R001", ConditionType.Standard, BedType.DoubleBedRoom, 2));
            hotel.AddRoom(new Room("R002", ConditionType.Superior, BedType.TripleBedRoom, 3));
            hotel.AddRoom(new Room("R003", ConditionType.Deluxe, BedType.ExtraBedRoom, 4));
            Room room = hotel.SearchRoom("R001");
            hotel.RemoveRoom(room);
            hotel.HotelInfo();



            // hotel.Rooms.Add(new Room("R001", ConditionType.Standard, BedType.DoubleBedRoom, 2));
            // hotel.Rooms.Add(new Room("R002", ConditionType.Superior, BedType.TripleBedRoom, 3));
            // hotel.Rooms.Add(new Room("R003", ConditionType.Deluxe, BedType.ExtraBedRoom, 4));

            // hotel.HotelInfo();

            // Console.WriteLine("Searching Process:");
            // Console.WriteLine(hotel.SearchRoom("R001").ConvertToString());
            // Console.WriteLine(hotel.SearchRoom("R004").ConvertToString());
            // Console.WriteLine(hotel.SearchRoom(2).ConvertToString());
            // Console.WriteLine(hotel.SearchRoom(3).ConvertToString());

            Console.ReadKey();
        }
    }
}

namespace MainData
{
    public enum ConditionType { Standard, Superior, Deluxe, Suite };
    public enum BedType { ConnectingRoom, SingleBedRoom, TwinBedRoom, DoubleBedRoom, TripleBedRoom, ExtraBedRoom };
    public class Room
    {
        string RoomID = "RM000";
        ConditionType condition = ConditionType.Standard;
        BedType bedtype = BedType.DoubleBedRoom;
        int Capacity = 2;
        public Room() { }
        public Room(string RoomID, ConditionType condition, BedType bedtype, int Capacity)
        {
            this.RoomID = RoomID;
            this.condition = condition;
            this.bedtype = bedtype;
            this.Capacity = Capacity;
        }
        public string ValRoomID
        {
            get { return RoomID; }
            set { RoomID = value; }
        }
        public ConditionType Valcondition
        {
            get { return condition; }
            set { condition = value; }
        }
        public BedType Valbedtype
        {
            get { return bedtype; }
            set { bedtype = value; }
        }
        public int Valcapacity
        {
            get { return Capacity; }
            set { Capacity = value; }
        }
        public void RoomInfo()
        {
            string conditionName = Enum.GetName(typeof(ConditionType), condition);
            string bedtypeName = Enum.GetName(typeof(BedType), bedtype);
            if (RoomID != "RM000")
                Console.WriteLine("Phong: {0} - {1} - {2} for {3} persons", RoomID, conditionName, bedtypeName, Capacity);
        }
    }
    public class Hotel
    {
        public List<Room> Rooms { get; set; }
        Dictionary<ConditionType, string> conditioninfo = new Dictionary<ConditionType, string>();
        string Name;
        public delegate void HotelHandler(Hotel hotel);
        public event HotelHandler HotelAddorRemoveEvent;
        public Hotel()
        {
            Rooms = new List<Room>();
            Name = "Not Assigned";
            conditioninfo.Add(ConditionType.Standard, "Phong standard la phong co chat luong va gia thap nhat");
            conditioninfo.Add(ConditionType.Superior, "Phong Superior dien tich lon hoac huong nhin đẹp");
            conditioninfo.Add(ConditionType.Deluxe, "Phong Superior co chat luong cao, thuong o tang cao");
            conditioninfo.Add(ConditionType.Suite, "Phong Superior o tang cao nhat voi cac trang bi va dich vu dac biet.");
        }
        public string ValName
        {
            get { return Name; }
            set { Name = value; }
        }
        public void HotelInfo()
        {
            Console.WriteLine("Khach San {0} co {1} phong. Gom cac phong nhu sau:", Name, NumberOfRoom);
            foreach (Room rm in Rooms)
            {
                KeyValuePair<ConditionType, string> info = conditioninfo.FirstOrDefault(o => o.Key == rm.Valcondition);

                rm.RoomInfo();
                Console.WriteLine("---Thong Tin Phong: {0}\n", info.Value);
            }
        }
        public Room SearchRoom<T>(T search)
        {
            Room r = new Room();
            if (typeof(T) == typeof(string))
            {
                r = Rooms.FirstOrDefault(o => o.ValRoomID == search.ToString());
                if (r != null)
                    return r;
            }
            else if (typeof(T) == typeof(int))
            {
                if (Convert.ToInt32(search) < Rooms.Count)
                    return Rooms[Convert.ToInt32(search)];
            }
            else Console.WriteLine("Room is not found");
            return new Room();
        }
        int NumberOfRoom = 0;
        public int ValNumberofRoom
        {
            get { return NumberOfRoom; }
            set { NumberOfRoom = value; }
        }
        public void AddRoom(Room room)
        {
            Rooms.Add(room);
            OnHotelChanger(this);
        }
        public void RemoveRoom(Room room)
        {
            Rooms.Remove(room);
            OnHotelChanger(this);
        }
        public void OnHotelChanger(Hotel hotel)
        {
            if (HotelAddorRemoveEvent != null)
            {
                HotelAddorRemoveEvent(this);
            }
        }
    }
    public static class MyExtensions
    {
        public static string ConvertToString(this Room room)
        {
            string conditionName = Enum.GetName(typeof(ConditionType), room.Valcondition);
            string bedtypeName = Enum.GetName(typeof(BedType), room.Valbedtype);
            if (room.ValRoomID != "RM000")
                return String.Format("Phong: {0} - {1} - {2} for {3} persons",
                             room.ValRoomID, conditionName, bedtypeName, room.Valcapacity);
            else
                return "";
        }
    }
}